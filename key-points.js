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
