#include <iostream>
#include <string>
#include <vector>
#include <functional>

using namespace std;

class User {
  public:
    string name;
    User(string n): name(n) {}
};

// Forward declare closure / C++ lambda
function<void()> getClosure(string val) {
  // User [=] to indicate capture variables, or catpure specific variables, rename them
  auto s_val = 43;
  auto innerFn = [c_val=val,cs_val=s_val] {
    cout << "Closure captured: " << c_val << ", " << cs_val << endl;
  };

  return innerFn;
}

int main() {

  User me("Student");
  cout << "User: " << me.name << endl;

  // C++ uses strict typing
  // This will fail compilation
  // vector<int> nums = {1, "one", '1', me};

  if(true) {
    string blockVal = "Only in block";
  }
  // Following will fail
  // cout << blockVal << endl;

  // Lambda example
  auto my_lambda = getClosure("from main");
  my_lambda();
  
  return 0;
}

