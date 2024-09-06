//You can use 2 stcks but if told to do in one stack only then store the other element in the same element.
//also used only if range is given like here 100 is given

class Solution{
    
    stack<int> s1;
    // stack<int> s2;
    public:
    
       /*returns min element from stack*/
       int getMin(){
        //   if(s2.empty()) return -1;
        //   return s2.top();

            if(s1.empty()){
                return -1;
            }
            return s1.top()%101;
            
           
       }
       
       /*returns poped element from stack*/
       int pop(){
           
        //   if(s1.empty()) return -1;
        //   int element=s1.top();
           
        //   s1.pop();
        //   s2.pop();
        //   return element;
        
        if(s1.empty()) return -1;
        int ele=s1.top()/101;
        s1.pop();
        return ele;
        
        
        
       }
       
       /*push element x into the stack*/
       void push(int x){
           
        //   if(s1.empty()){
        //       s1.push(x);
        //       s2.push(x);
        //   }else{
        //       s1.push(x);
        //       s2.push(min(s2.top(),x));
        //   }
        
        
            if(s1.empty()){
                s1.push(x*101+x);
            }else{
                s1.push(x*101+min(s1.top()%101,x));
            }
           
       }
};