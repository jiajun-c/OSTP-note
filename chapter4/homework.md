# The cpu-intro

1. 
The result should be 
run ready
run ready
run ready
run ready
run ready
done run 
done run 
done run 
done run
done run 

2. 
The result should be 
run ready
run ready
run ready 
run ready 
run ready 
done run:io
done waiting
done waiting
done waiting 
done waiting
done waiting
done done:io

3.
The result should be 
run:io ready
waiting run
waiting run 
waiting run 
waiting run 
waiting done 
run:io_done done

4. 
In the problem, only after the process is ended, another process will run 
So it is may be like 
run:io ready
waiting ready 
waiting ready
waiting ready
waiting ready
waiting ready
run:io_end run 
done    run
done    run
done    run
done    run 

5. 
The strategy will be switch to another process when the another process is waiting. 
So the result should be like 3 

6. 
It is hard to compare .

7. 
After the end of the io, the process run immediately.
So it will the higher effectiveness. 

8.
They may stay the same, while the switch-on-end still low.
