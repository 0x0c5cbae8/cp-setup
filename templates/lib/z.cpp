#include <templates/init>

// z[i] = max x s.t. s[0..x-1] == s[i..i+x-1]
vi Z(const string& s){
    vi z(sz(s));
    int l=0, r=0;
    for(int i=1;i<sz(s);i++){
        if(i<r) z[i]=min(z[i-l], r-i);
        while(i+z[i]<sz(s)&&s[z[i]]==s[i+z[i]])z[i]++;
        if(i+z[i]>r) l=i, r=i+z[i];
    }
    return z;
}
