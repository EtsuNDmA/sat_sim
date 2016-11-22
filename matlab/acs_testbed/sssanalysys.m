k=0.1;
ga=0.001;
g=10;
K=diag([k k k]);
Ga=diag([ga ga ga]);
G=[0 1 g;1 0 1;-g 1 0];
A=[-K G;Ga zeros(3)];


sys=ss(A,zeros(6),eye(6),0);
plot(pole(sys),'x');
grid on;

MC=ctrb(sys); 
fprintf('Rank of MC is %d\n',rank(MC))