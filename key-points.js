const data = {
  "users": [
    {
      "id": 1,
      "name": "John",
      "age": 25,
      "hobbies": ["reading", "gaming"],
      "address": {
        "street": "123 Main St",
        "city": "Anytown",
        "state": "CA",
        "zip": "12345"
      }
    },
    {
      "id": 2,
      "name": "Jane",
      "age": 30,
      "hobbies": ["hiking", "photography"],
      "address": {
        "street": "456 Oak St",
        "city": "Someville",
        "state": "NY",
        "zip": "54321"
      }
    },
    {
      "id": 3,
      "name": "Bob",
      "age": 35,
      "hobbies": ["cooking"],
      "address": {
        "street": "789 Elm St",
        "city": "Othercity",
        "state": "FL",
        "zip": "67890"
      }
    }
  ]
};

// Filter users over age 30 and return their names and hobbies
const filteredUsers = data.users.filter(user => user.age > 30)
                                .map(user => ({name: user.name, hobbies: user.hobbies}));

console.log(filteredUsers);


In this example, we have a JSON object with an array of users. We use the filter() method to filter the users over the age of 30, and then the map() method to return an array of objects containing only the user's name and hobbies. The resulting filteredUsers array will contain two objects representing users Jane and Bob:

[  {    "name": "Jane",    "hobbies": ["hiking", "photography"]
  },
  {
    "name": "Bob",
    "hobbies": ["cooking"]
  }
 
]

data.users.filter(user => user.hobbies.includes("gaming"));  //user whose hobbies include gaming

let productId = this.route.snapshot.paramMap.get('id');

const data = [
  {
    "StoryPoints": -1,
    "TaskEstimate": -100
  },
  {
    "StoryPoints": 41,
    "TaskEstimate": -100
  },
  {
    "StoryPoints": 71,
    "TaskEstimate": -100
  }
];

data.sort((a, b) => a.StoryPoints - b.StoryPoints);

console.log(data);

async fetchUsers() {
  try {
    const response = await fetch('https://randomuser.me/api/?results=5');
    const data = await response.json();
    console.log(data.results);
  } catch (error) {
    console.error(error);
  }
}
A function along with reference to its outer environment together forms a closure. Or in other words, A Closure is a combination of a function and its lexical scope bundled together. eg:

result.erase(std::unique(result.begin(), result.end()), result.end());
filters duplicate vectors in 2D vector
