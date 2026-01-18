#include <iostream>
#include <vector>

using namespace std;

vector<int>* dataGen(int count) {

  // The new keywords allows for manual memory management
  auto data = new vector<int>();

  for(auto i=0; i<count; i++) {
    data->push_back(i * 2);
  }

  return data;
}

int main() {

  // Memory for temp is automatically managed by C++
  string temp;
  
  cout << "Application starting" << endl;

  cout << "Press any key to setup large memory use" << endl;
  cin >> temp;
  
  auto data = dataGen(1000000);
  cout << "Data ready" << endl;
  cout << "Size: " << data->size() << endl;

  cout << "Press any key to clean up data" << endl;
  cin >> temp;
  
  // Comment the below to create a memory leak!
  // delete data;

  cout << "Press any key to exit" << endl;
  cin >> temp;

  // Memory for temp automatically cleared as the 
  // variable goes out of scope here
}
