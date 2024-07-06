#include<stdio.h>
int main(){
    int incoming, outgoing, buck_capacity, n, store = 0;
    printf(&quot;Enter bucket capacity, outgoing rate and no of inputs: &quot;);
    scanf(&quot;%d %d %d&quot;, &amp;buck_capacity, &amp;outgoing, &amp;n);
    while (n != 0) { //loop over total number of inputs
        printf(&quot;Enter the number of incoming packets: &quot;);
        scanf(&quot;%d&quot;, &amp;incoming);
        printf(&quot;Incoming packet size %d\n&quot;, incoming);
    if((incoming-outgoing) &lt;= (buck_capacity-store)) //it is possible to send without dropping
    {
      int sent = outgoing&gt;=incoming?incoming:outgoing; //if incoming is more than outgoing, total
      sent will be outgoing rest buff
      if(sent &lt; outgoing &amp;&amp; store != 0)  //if incoming&lt;outgoing, we can add values from the store to be sent till op cap is reached
      { 
        int remaining = outgoing-sent;
        while(remaining &gt; 0 &amp;&amp; store != 0) //keeps adding one to sent until we run out of op cap or nothing left in buff
        {
          remaining -= 1;
          store -= 1;
          sent += 1;
        }
      }
      printf(&quot;%d packets sent out\n&quot;, sent);
      if(outgoing&lt;incoming)
      {
        store = store + (incoming - outgoing);
      }
    }
    else //packets need to be dropped
    {
      int dropped = (incoming-outgoing)-(buck_capacity-store); //excess packets are the ones that
      after sending cant be accomodated in buff
      printf(&quot;%d packets dropped\n&quot;, dropped);
      store = buck_capacity;
    }
    printf(&quot;%d out of %d space used in the buffer\n&quot;, store, buck_capacity);
            n--;
    }
}
