#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    for(auto it : v){
        cout<<it;
    }
   // check whether element present  in  a vector
    v = {2,3,4};

  if (std::find(v.begin(), v.end(),3)!=v.end()) { // it's not possible now, but how?
    std::cout << "yo" << std::endl;
  }
    async fetchUsers() {
  try {
    const response = await fetch('https://randomuser.me/api/?results=5');
    const data = await response.json();
    console.log(data.results);
  } catch (error) {
    console.error(error);
  }
}
    return 0;
}
