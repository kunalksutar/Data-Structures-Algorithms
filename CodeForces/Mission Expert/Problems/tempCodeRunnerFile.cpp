        cin>>a[i];
    }

    rep(i,0,n){
        cin>>b[i];      
    }

    sort(all(a));
    sort(all(b));

    vi ans(n);
    int i=0,j=0;  //through b

    int cost=0;

    for(;i<n;i++){
        if(a[n-i]>b[j]){
            ans[n-i]=b[j];
            j++;
            cost++;
        }else break;

        if(cost==k)break;
    }

    if(cost!=k){
        cout<<"NO"<<endl;
        return;
    }

    cout<<"YES"<<endl;

    int i=0;

    while(j<n){
        ans[i]=b[j];
        j++;i++;
    }