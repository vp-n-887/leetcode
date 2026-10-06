int smallestNumber(int n, int t) {
    while(n){

        int prod=1;
        int temp=n;
        while(temp)
        {
            int r=temp%10;
            prod=prod*r;
            temp=temp/10;
        }
       if(prod%t==0){return n;}
       n++;
    }
    return -1;
}