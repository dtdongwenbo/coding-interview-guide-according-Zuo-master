#include <string>
#include <queue>
#include <iostream>
using namespace std;
//pet dog cat题目中的声明及实现
class Pet
{
	public:
		Pet(string type)
		{
			this->type = type;
		}
		string getPetType()
		{
			return type;
		}
	private:
		string type;
 };
 class Dog:public Pet
 {
 	public:
 		Dog():Pet("dog"){}
		 
  };
  class Cat:public Pet
  {
  	public:
  		Cat():Pet("cat"){}
  };
  //带时间戳的宠物类声明及实现
  class PetStamp
  {
  	public:
  		PetStamp(Pet p,long count):pet(p)
  		{
  			this->count = count;
		  }
		Pet getPet()
		{
			return pet;
		}
		long getCount()
		{
			return count;
		}
		string getPetType()
		{
			return pet.getPetType();
		}
	private:
		Pet pet;
		long count;
  };
  class CatDogQue
  {
  	public:
  		CatDogQue();
  		void push(Pet pet);
  		Pet popAll();
  		Dog popDog();
  		Cat popCat();
  		bool isEmpty();
  		bool isDogEmpty();
  		bool isCatEmpty();
  	private:
  		queue<PetStamp> dogQ;
  		queue<PetStamp> catQ;
  		long count;
  };
 CatDogQue::CatDogQue()
  {
  	count = 0;
  }
 void CatDogQue::push(Pet pet)
 {
 	if("dog" == pet.getPetType())
 		dogQ.push(PetStamp(pet,count++));
 	else if("cat" == pet.getPetType())
 		catQ.push(PetStamp(pet,count++));
 	else
 		cout<<"error";
 	return ;
 	
 }   
Pet CatDogQue::popAll()
{
	if(!catQ.empty() && !dogQ.empty())
	{
		if(dogQ.front().getCount() < catQ.front().getCount())
		{
			Pet tmp = dogQ.front().getPet();
			dogQ.pop();
			return tmp;
		}
		else
		{
			Pet tmp = catQ.front().getPet();
			catQ.pop();
			return tmp;
		}
	}
	else if(!catQ.empty())
	{
		Pet tmp = catQ.front().getPet();
		catQ.pop();
		return tmp;
		
	}
	else if(!dogQ.empty())
	{
		Pet tmp = dogQ.front().getPet();
		dogQ.pop();
		return tmp;
		
	}
	else
	{
		cout<<"error";

	}
}
Dog CatDogQue::popDog()
{
	if(!dogQ.empty())
	{
		Pet tmpP = dogQ.front().getPet();
		Dog tmpD;//实现父类将值赋值给子类 
		Pet *pd = &tmpD;
		*pd = tmpP;
		
		dogQ.pop();
		return tmpD;
	}
 } 
Cat CatDogQue::popCat()
{
	if(!dogQ.empty())
	{
		Pet tmpP = catQ.front().getPet();
		Cat tmpC;
		Pet *pc;
		pc = &tmpC;
		*pc = tmpP;
		
		catQ.pop();
		return tmpC;
	}
 } 
 bool CatDogQue::isEmpty()
 {
 	return dogQ.empty()&&catQ.empty();
 }
 bool CatDogQue::isDogEmpty()
 {
 	return dogQ.empty();
 	
 }
 bool CatDogQue::isCatEmpty()
 {
 	return catQ.empty();
 }
int main()
{
    CatDogQue cdq;
    if(cdq.isEmpty())
        cout << "All queue is empty!" << endl;
     cdq.push(Dog());//等于Dog dog;cdq.push(dog); 
    if(!cdq.isDogEmpty())
        cout << "Dog queue is not empty!" << endl;
    if(cdq.isCatEmpty())
        cout << "Cat queue is Empty!" << endl;
    for(int i=0;i<2;i++)
    {
        cdq.push(Cat());
        cdq.push(Dog());
    }
    cout << "popAll:" << cdq.popAll().getPetType() << endl;
    cout << "popDog:" << cdq.popDog().getPetType() << endl;
    cout << "popCat:" << cdq.popCat().getPetType() << endl;    
    cout << "popAll:" << cdq.popAll().getPetType() << endl;
    cout << "popAll:" << cdq.popAll().getPetType() << endl;
    if(cdq.isEmpty())
        cout << "All queue is empty!" << endl;

    return 0;
}
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
