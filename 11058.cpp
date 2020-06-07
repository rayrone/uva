#include<stdio.h>
#include<string.h>

/* Encoding - 11058 */

main(){
    
    int i,j,c=0,r,p;
      
    char k,l,a[101],s[101];
    
    while(scanf("%s",s)!=EOF){
        
        strcpy(a,s);
        
        for(i=0;i<26;i++)
        {
          scanf("\n%c",&l);
          for(j=0;s[j]!='\0';j++)
           if(s[j] == 'a'+i)
             a[j] = l;
        }
        
        scanf("%d",&r);
        
        for(i=1;i<=r;i++)
        {
           scanf("%d %c %c",&p,&k,&l);
           for(j=p;s[j]!='\0';j++)
             if(s[j] == k)
              a[j] = l;
              
        }
        
        printf("Case #%d: The encoding string is %s.\n\n",++c,a);  
        
    } 
    
}
