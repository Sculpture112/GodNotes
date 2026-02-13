```cpp
https://www.nowcoder.com/share/jump/716254661768985086631
```

```cpp
long long legalExp(string str) {
        // write code here
        stack<long long> s;
        long long cur_num =0;

        for(char c:str){
            if(isdigit(c)){
                cur_num = cur_num*10 + (c - '0');
            }
            else if(c=='#'){
                s.push(cur_num);
                cur_num=0;
            }
            else if(c=='+'||c=='-'||c=='*'){
                long long v2 = s.top();s.pop();
                long long v1 = s.top();s.pop();

                if(c=='+') s.push(v1+v2);
                else if(c=='-') s.push(v1-v2);
                else if(c=='*') s.push(v1*v2);
            }
        }
        return s.top();
    }
```