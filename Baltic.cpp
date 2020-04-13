    /*
     * I dont know why this is right but it works 
     * let num is number of leaves in the tree , try to connect leaf[i] with leaf[i+num/2] 
     * you will face some problems when num is odd so you should be carefull 
    */
    #define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
    #include <bits/stdc++.h>
    using namespace std;
    #define sqr 340
    #define mid (l+r)/2
    #define pb push_back
    #define ppb pop_back
    #define fi first
    #define se second
    #define lb lower_bound
    #define ub upper_bound
    #define ins insert
    #define era erase
    #define C continue
    #define mem(dp,i) memset(dp,i,sizeof(dp))
    #define mset multiset
    typedef long long ll;
    typedef short int si;
    typedef long double ld;
    typedef pair<int,int> pi;
    typedef pair<ll,ll> pll;
    typedef vector<int> vi;
    typedef vector<ll> vll;
    typedef vector<pi> vpi;
    typedef vector<pll> vpll;
    const ll inf=1e18;
    const ld pai=acos(-1);
    int n , root ;
    vi v[500009] , leaves;
    void dfs( int node , int p ) {
            if ( v[node].size() == 1 ) leaves . pb ( node ) ;
            for ( auto u : v[ node ] ) {
                    if ( u == p ) C ;
                    dfs ( u , node ) ;
            }
    }
    int main () {
            cin >> n ;
            for ( int i = 0 ; i < n-1 ; i ++ ) {
                    int a , b ;
                    cin >> a >> b ;
                    a -- , b -- ;
                    v[a].pb ( b ) ;
                    v[b].pb ( a ) ;
            }
            for ( int i = 0 ; i < n ;i ++ ) {
                    if ( v[i].size() != 1 ) {
                            root = i ;
                            break ;
                    }
            }
            dfs(root,root);
            vpi ans ;
            int num = leaves.size() ;
            for ( int i = 0 ; i < num/2 ; i ++ ) {
                    int j = i + num/2 + (num%2) ;
                    if ( j >= num ) break ;
                    int a = leaves[i] ;
                    int b = leaves[j] ;
                    ans.pb ( { a+1 , b+1 } );
            }
              if ( num%2 ) ans.pb ( { leaves[num/2]+1 , leaves[0]+1 } ) ;
            cout << ans.size() << endl ;
            for ( auto u : ans ) cout << u.fi << " " << u.se << endl ;
    }
