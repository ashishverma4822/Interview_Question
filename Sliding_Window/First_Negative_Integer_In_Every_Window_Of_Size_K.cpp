
typedef long long ll;
typedef long long int lli;
vector<ll> printFirstNegativeInteger(lli A[], lli N, lli K) {
    ll i=0,j=0;
    deque<ll>d;
    vector<ll>v;
    while(j<N){
        if(A[j]<0){
            d.push_back(A[j]);
        }
        if(j-i+1<K){
            j++;
        }
        else if(j-i+1==K){
            if(d.size()==0){
                v.push_back(0);
            }
            else{
                v.push_back(d.front());
                if(d.front()==A[i]){
                    d.pop_front();
                }
            }
            i++;
            j++;
        }
    }
    return v;                             
 }