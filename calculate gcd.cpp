#include <iostream> 
using namespace std; 
   
// Recursive GCD 
int gcdRecursive(int a, int b) { 
  return (b==0) ? a: gcdRecursive(b, a% b); 
} 
 
// Non-recursive GCD 
int gcdIterative(int a, int b) { 
   while (b != 0) { 
       int temp =b; 
       b = a%b;
       a =temp; 
   } 
   return a; 
}  
int main() {  
   int a, b;  
   cout<< "Enter two numbers (seperated by space): "; 
   cin >> a >> b; 
   
   cout << "GCD (Recursive):  "<< gcdRecursive(a, b) << endl;  
   cout << "GCD (Iterative): "<< gcdIterative(a, b)<< endl;  
   return 0; 
} 
