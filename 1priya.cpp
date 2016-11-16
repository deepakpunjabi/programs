int n,k;
    cin>>n>>k;
    vector<int>candy(n);
    for(int i=0;i<n;i++){
        cin>>candy[i];
    }
    int s=0,cnt=0,res=INT_MAX;

    /*for(int i=1;i<n;i++){
        if(candy[i]){
            
            int v=i-s;
            if(cnt){
                v=k*v;
            }
            res+=v;
            cnt++;
            s=i;
            if(cnt==2)break;
        }
    }*/
    int dp[n];dp[0]=0;
    for(int i=1;i<n-1;i++){
        dp[i]=INT_MAX;
        if(!candy[i])continue;
        for(int j=i+1;j<n;j++){
            if(candy[j]){
                //cout<<i<<" "<<j<<" "<<k<<endl;
                dp[i]=k*(j-i)+i;
                //cout<<"debug:"<<dp[3]<<endl;
                break;
            }
        }
        res=min(dp[i],res);
    }
    /*for(int i=0;i<n;i++){
        cout<<dp[i]<<endl;
    }*/
    cout<<res<<endl;
    return 0;