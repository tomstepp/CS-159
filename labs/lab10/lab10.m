%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  Programmers and Purdue Email Addresses:
%  1. steppt@purdue.edu
%  2. ddecarde@purdue.edu
%  3. hu234@purdue.edu
%
%  Lab #: 10
%
%  Academic Integrity Statement:
%
%       We have not used source code obtained from
%       any other unauthorized source, either modified
%       or unmodified.  Neither have we provided access 
%       to our code to another. The project we are submitting
%       is our own original work.
%
%  Lab Division and Section: div 08 sec 01
%
%  Program Description: remove double integers of a value from an external file.
%
%  Listing and Commenting of All Variables Used:
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

fh = fopen('labData', 'r'); % fh == -1 if failed to open
x = feof(fh); % x=true if reached end of file
num = 0;
newnum = 1;

if (~x)

%num = fscanf(fh, '%ld',1);

while((num ~= newnum)&&(newnum ~= 0))
num = fscanf(fh, '%ld',1);

%while((num ~= newnum)&&(newnum ~= 0))
test = num; % duplicate of original used for calculations 
length = 0; % initialization of variable used to count digits
ct = 0; % initialization of varaible used to count iterations of inner while loop
newnum = 1;% initialization of variable used to record the number after removal of double digit
recurse = 0;% initialization of variable used to record number of outer loop iterations

fprintf('\nOriginal: %ld\n',num);
fprintf('Changes: ');

  if (recurse > 0)
    num = newnum;
    test = newnum;
    length = 0;
    ct = 0;
  end

  while(test > 0)   % finds number of digits
    test = floor(test / 10);
    length = length + 1;
  end

  num1 = mod(num,10^1);
  num2 = floor(mod(num,10^(2))/10);

  while((num1 ~= num2) && (ct ~= length)) %compares digits
    ct = ct + 1;
    num1 = floor(mod(num,10^(ct+1))/ (10^ct));
    num2 = floor(mod(num,10^(ct+2)) / (10^(ct+1)));

  end

  newnum  = ((num - (mod(num,10^(ct+2))))/(10^(ct+2)))*10^(ct)+(mod(num,10^(ct))) ;% gets newnumber

  if ((newnum == num)&&(recurse ==0))
    fprintf('No changes made.\n');
  else
    if recurse > 0
      fprintf(' -> %ld', newnum);
    else 
      fprintf('%ld', newnum);
    end
    %fprintf(' -> %ld', newnum);
  end

  recurse = recurse + 1;

end

fprintf('\n');

end

fclose(fh); %Close file


