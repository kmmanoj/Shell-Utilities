Here is the command, that is more flexible than the shell command

Compile the c code as :
<code>gcc exe.c -o exe</code>

and move the executable to : <code>/usr/local/bin</code>
Now, you can use this command as follows:

<b>USAGE:</b>
 exe program_file options  
 exe program_file input_file output_file
 exe program_file input_file 

<b>OPTIONS:  </b>
 -i input_file         
 --input input_file    To provide the input for the execution of the C program

 -o output_file        
 --output output_file  To redirect the output into output_file

 -h                    
 --help                Shows usage 
