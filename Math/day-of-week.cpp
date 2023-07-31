//https://leetcode.com/problems/day-of-the-week/description/
class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
                int months[13] = {31,28,31,30,31,30,31,31,30,31,30,31};
                string dayName[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
                int sum =4; //since v r starting frm 1st jan 1971. anf its a friday
                for(int i=1971;i<year;i++){
                    if((i%4==0 && i%100!=0)||(i%400==0)){ //leap year check
                        sum+=366;
                    }
                    else{
                        sum+=365;
                    }
                }
                for(int i=0;i<month-1;i++){
                    if(i==1 && ((year%4==0 && year%100!=0)||(year%400==0))){ //leap year check
                        sum+=1;
                    }
                    else{
                       
                        sum+=months[i];
                    }
                }
               
                sum+=day;
               cout<<sum;
                return dayName[sum%7];

    }
};
