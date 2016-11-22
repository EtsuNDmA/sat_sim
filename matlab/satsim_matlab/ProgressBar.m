clc
Progress=StepModel/MaxStepModel*100;
disp(floor(Progress))
if Progress<10      disp('|>0%                                         |');
elseif Progress<20  disp('|---->  10%                                  |');
elseif Progress<30  disp('|--------> 20%                               |');
elseif Progress<40  disp('|------------->30%                           |');
elseif Progress<50  disp('|---------------->40%                        |');
elseif Progress<60  disp('|-------------------->50%                    |');
elseif Progress<70  disp('|------------------------>60%                |');
elseif Progress<80  disp('|---------------------------->70%            |');
elseif Progress<90  disp('|-------------------------------->80%        |');
elseif Progress<99  disp('|------------------------------------>90%    |');
else                disp('|------------------------------------------->|');
end