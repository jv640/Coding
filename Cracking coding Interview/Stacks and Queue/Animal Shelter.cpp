/*
  Description : Animal Shelter: An animal shelter, which holds only dogs and cats, operates on a strictly "first in, first out" basis. 
                People must adopt either the "oldest" (based on arrival time) of all animals at the shelter, or they can select whether they would prefer a dog or a cat 
                (and will receive the oldest animal of that type). They cannot select which specific animal they would like. 
                Create the data structures to maintain this system and implement operations such as enqueue, dequeueAny, dequeueDog, and dequeueCat. 
                You may use the built-in Linked List data structure. 
*/

/*
  Here approach is to use 2 different list each for dog and cat and also when adding element we can add the counter value also with them both list will share same variable age
  lower the value of age older the animal so for enqueue first we will check whether new animal is dog or cat and then insert it into approapriate list also increase age.
  to implement dequeueAny first we will check whether both list are emppty or not if empty then return -1 if any one list is empty then dequeue from the other one if none of list
  is empty then take first element of each dog and cat and compare their age variable whichever is smaller dequeue that one. other 2 dequeue are simple to implement
*/

// code
class Animal Shelter{
  list<int> cats, dogs;
  int age = 0;
  public:
    void enqueue(string animal){
      if(animal.compare('Dog')
        dogs.push_back(++age);
      else
        cats.push_back(++age);
    }
    void dequeuAny(){
      if(dogs.size() == 0 && cats.size() == 0)
        return;
      if(dogs.size() == 0)
        dequeueDogs();
      if(cats.size() == 0)
        dequeueCats();
      if(dogs.front() > cats.front())
        dequeueCats();
      else
        dequeueDogs();
    }
    void dequeueDogs(){
      if(dogs.size() == 0)
        return;
      dogs.pop_front();
    }
    void dequeueCats(){
      if(Cats.size() == 0)
        return;
      Cats.pop_front();
    }
}
