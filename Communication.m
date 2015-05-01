% Amplitude modulation and demodulation --------------------------------------

clc;
close all;

t=-10:0.01:10;

fm=.1;
fc=5;

ym=cos(2*pi*fm*t);
yc=cos(2*pi*fc*t);
y=ym.*yc;

subplot(3,2,1)
plot(t,ym,'r')

subplot(3,2,2)
plot(t,yc,'r')

subplot(3,2,3)
plot(t,y,'b')

%Receiver side
v=yc.*y;
subplot(3,2,4)
plot(t,v,'g')

%filter
n=20;
wn=0.1;
[B,A] = butter(n,wn,'low');  % total values of A and B will be n=20

%filter output yy
yy = filter(B,A,v);
subplot(3,2,5)
plot(t,yy,'r')

% AMplitude modulation with career ------------------------------------ *****************************
clc;
close all;

t=-10:0.01:10;

fm=input('Fm : ');  % value=.1
fc=input('fc : ');  % value=3

Am=input('Am : ');
Ac=input('Ac : ');

ym=Am.*cos(2*pi*fm*t);
yc=Ac.*cos(2*pi*fc*t);
y=(1+ym).*yc;

subplot(3,2,1)
plot(t,ym,'r')

subplot(3,2,2)
plot(t,yc,'r')

subplot(3,2,3)
plot(t,y,'b')

%Receiver side
v=yc.*y;
subplot(3,2,4)
plot(t,v,'g')

%filter
n=20;
wn=0.1;
[B,A] = butter(n,wn,'low');  % total values of A and B will be n=20

%filter output yy
yy = filter(B,A,v);
subplot(3,2,5)
plot(t,yy,'r')

% Frequency modulation--------------------------------------------------------------------

clc;
close all;

t=-10:0.01:10;

beta = 20;


fm=0.1;
fc=3;
Am=1;
Ac=1;

%modulate freq
Fm=Ac.*cos(2*pi*fc*t + beta.*sin(2*pi*fm*t));

ym=Am.*cos(2*pi*fm*t);
yc=Ac.*cos(2*pi*fc*t);


subplot(3,2,1)
plot(t,ym,'g')

subplot(3,2,2)
plot(t,yc,'g')

subplot(3,2,3);
plot(t,Fm,'b')

y = ym.*yc;
%demodulation
sampeling_freq = 100;   % time interval
x = demod(Fm,fc,sampeling_freq,'fm'); 
subplot(3,2,4);
plot(t,x);


