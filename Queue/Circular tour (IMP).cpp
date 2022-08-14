//https://practice.geeksforgeeks.org/problems/circular-tour-1587115620/1

The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

//start traversing from 0th index,maitain a petrol balance if petrol needed is insufficient, change the starting
//point to next one, memoize the balance which was on shortage, and then reset balance since we are starting
//from different index. after the loop completed we'l get the result
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       int deficit =0; //it is the shortage that we make a note and memoize. when we traverse first
       int balance = 0;
       int start=0;
       
       for(int i=0;i<n;i++){
           balance+=p[i].petrol - p[i].distance;
           if(balance<0){
               start = i+1; //new start point
               deficit += balance; //memoize the shortage to use it later
               balance = 0; //since we are changing start point and starting again
           }
       }
       
       if(deficit + balance >=0){
           return start;
       }
       
       return -1;
    }
};
