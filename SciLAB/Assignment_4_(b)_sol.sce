// 1 --------------------------------------------------------

clc;
clear;

data=[39,200,42,15,67,276,27,66]
names=['EUL' , 'PES',' EFA',' EDD',' ELDR',' EPP',' UEN',' Other']

subplot(1,2,1)
pie(data,names)
title("Election results")

subplot(1,2,2)
bar(data,1,'green')   // bar(y,x,color)
title("Election results")

//2  --------------------------------------------------------

scf(2)
filename=fullfile('C:\Users\co250\Desktop','image.txt')   // fullfile(path,file name)
M=csvRead(filename,ascii(9),' ','double')
histplot(20,M)          // histogram

//3  -------------------------------------------------------
function drawCircle(x,y,r)
   theta = 0 : 0.1 : 2*%pi + 1
   x_c = x + r*cos(theta)
   y_c = y + r*sin(theta)
   plot(x_c,y_c)
endfunction

function clearCircle(x,y,r)
    theta = 0: 0.1 : 2*%pi + 1
    x_c = x + r*cos(theta)
    y_c = y + r*sin(theta)
    plot(x_c,y_c,'w-')
endfunction

function z = f(r)
    radius = r
    inner_radius = radius
    displacement = 5
    PAUSE_TIME = 500
    truncate = radius + inner_radius + displacement
    square(-truncate,0,truncate,truncate)
    theta = 0 
    alpha = 0
    x_centre = 0
    y_centre = truncate/2
    drawCircle(x_centre,y_centre,radius+inner_radius)
    while %T
        if(input=="3") then
            break
        end
        x_coordinate = radius*(cos(theta)) + x_centre
        y_coordinate = radius*(sin(theta)) + y_centre
        theta = theta + 0.1
        drawCircle(x_coordinate,y_coordinate,inner_radius)
        sleep(PAUSE_TIME)
        clearCircle(x_coordinate,y_coordinate,inner_radius)
        drawCircle(x_centre,y_centre,radius+inner_radius)
    end
    z = 0
endfunction

f(1);

//4  ---------------------------------------------------------
function circle(xc,yc)
    a = 0:0.1:2*%pi;
    x = xc + cos(a);
    y = yc + sin(a);
    plot(x,y);
endfunction

function delcircle(xc,yc)
    a = 0:0.1:2*%pi;
    x = xc + cos(a);
    y = yc + sin(a);
    plot(x,y,'w');
endfunction

function line(x1,y1,x2,y2)
    x = [x1 x2];
    y = [y1 y2];
    plot(x,y)
endfunction

function delline(x1,y1,x2,y2)
    x = [x1 x2];
    y = [y1 y2];
    plot(x,y,'w');
endfunction

square(0, 0, 10, 10);
for i = 0:0.3:6
    circle(3+i,5);
    line(3+i,2,3+i,4);
    line(2+i,3,4+i,3);
    line(2+i,0,3+i,2);
    line(3+i,2,4+i,0);
    sleep(500);
    delcircle(3+i,5);
    delline(3+i,2,3+i,4);
    delline(2+i,3,4+i,3);
    delline(2+i,0,3+i,2);
    delline(3+i,2,4+i,0);
end

