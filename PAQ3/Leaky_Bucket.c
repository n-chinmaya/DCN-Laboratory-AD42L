#include<stdio.h>
int main(){
    int incoming, outgoing, buck_capacity, n, store = 0;
    printf("Enter bucket capacity, outgoing rate and no of inputs: ");
    scanf("%d %d %d", &buck_capacity, &outgoing, &n);
    while (n != 0) {
        printf("Enter the number of incoming packets: ");
        scanf("%d%", &incoming);
        printf("Incoming packet size %d\n", incoming);
        if((incoming-outgoing) <= (buck_capacity-store)){
          int sent = outgoing >=incoming?incoming:outgoing;
          if(sent < outgoing && store != 0)
          { 
            int remaining = outgoing-sent;
            while(remaining > 0 && store != 0)
            {
              remaining -= 1;
              store -= 1;
              sent += 1;
            }
          }
          printf("%d packets sent out\n", sent);
          if(outgoing < incoming){
            store = store + (incoming - outgoing);
          }
        }
        else{
          int dropped = (incoming-outgoing)-(buck_capacity-store);
          printf("%d packets dropped\n", dropped);
          store = buck_capacity;
        }
        printf("%d out of %d space used in the buffer\n", store, buck_capacity);
            n--;
    }
}
