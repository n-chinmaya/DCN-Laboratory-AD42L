#include&lt;stdio.h&gt;
void main() {
  int data[10];
  intdataatrec[10],c,c1,c2,c3,i;
  printf(&quot;Enter 4 bits of data one by one\n&quot;);
  scanf(&quot;%d&quot;,&amp;data[0]);
  scanf(&quot;%d&quot;,&amp;data[1]);
  scanf(&quot;%d&quot;,&amp;data[2]);
  scanf(&quot;%d&quot;,&amp;data[4]);

  //Calculation of even parity
  data[6]=data[0]^data[2]^data[4];
  data[5]=data[0]^data[1]^data[4];
  data[3]=data[0]^data[1]^data[2];
  printf(&quot;\nEncoded data is\n&quot;);
  for(i=0;i&lt;7;i++)
    printf(&quot;%d&quot;,data[i]);
  printf(&quot;\n\nEnter received data bits one by one\n&quot;);
  for(i=0;i&lt;7;i++)
    scanf(&quot;%d&quot;,&amp;dataatrec[i]);
  c1=dataatrec[6]^dataatrec[4]^dataatrec[2]^dataatrec[0];
  c2=dataatrec[5]^dataatrec[4]^dataatrec[1]^dataatrec[0];
  c3=dataatrec[3]^dataatrec[2]^dataatrec[1]^dataatrec[0];
  c=c3*4+c2*2+c1;
  if(c==0) {
    printf(&quot;\nNo error while transmission of data\n&quot;);
  }
  else {
    printf(&quot;\nError on position %d&quot;,c);
    printf(&quot;\nData sent : &quot;);
    for(i=0;i&lt;7;i++)
    printf(&quot;%d&quot;,data[i]);
    printf(&quot;\nData received : &quot;);
    for(i=0;i&lt;7;i++)
    printf(&quot;%d&quot;,dataatrec[i]);
    printf(&quot;\nCorrect message is\n&quot;);
    //if errorneous bit is 0 we complement it else vice versa
    if(dataatrec[7-c]==0)
    dataatrec[7-c]=1;
    else
    dataatrec[7-c]=0;
    for (i=0;i&lt;7;i++) {
      printf(&quot;%d&quot;,dataatrec[i]);
    }
  }
}
