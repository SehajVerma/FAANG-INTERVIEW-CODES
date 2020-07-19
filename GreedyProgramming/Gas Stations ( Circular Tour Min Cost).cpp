int tour(petrolPump p[],int n)
{
   //Your code here
   int sum=0;
   int diff=0;
   int start=0;
   for(int i=0;i<n;i++)
   {
       sum=sum+(p[i].petrol - p[i].distance);
       if(sum<0)
       {
           start=i+1;
           diff+=sum;
           sum=0;
           
       }
   }
   if((sum+diff)>=0 && start<n) 
   return start;
   else
   return -1;
}
