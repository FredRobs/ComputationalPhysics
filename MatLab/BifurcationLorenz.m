clear
clear global
%[text] 
%parametes
rho=28;
sigma=10;


%inital conditions
init=[0.0,0.1,0.0];

%stepsize
stepsize=0.001;

%range
range= 0.4:0.0005:0.8;

%initalise poincare matrix
intersection=NaN*zeros(1000,length(range));
position=0;

%ODE options
options=odeset('RelTol',1e-5,'AbsTol',1e-5);
%[text] 
function model = lorenz(t,x,sigma,rho,beta)
    model=[sigma*(x(2)-x(1));
        x(1)*(rho-x(3))-x(2);
        x(1)*x(2)-beta*x(3)];
end
%[text] 

%Bifurcation loop
for beta=range
    beta
    position=position+1;
    %obtain model
    modelFunction=@(t,x)lorenz(t,x,sigma,rho,beta);
    
    %simulate system
    [t,x]=ode45(modelFunction,0:stepsize:1000,init,options);
    
    %consider transient time
    cutoff=t>200;
    Xout=x(cutoff,:);

    temp=1;
    for i=2:length(Xout)
        %has it crossed section?
        if Xout(i,1)<0 && Xout(i-1,1)>0
             %save intersection value
            intersection(temp,position)=Xout(i,1);
            temp=temp+1;
        end
    end
end


hold on
plot(range,intersection,'.k','MarkerSize',2)
xlabel('\beta')
ylabel('x_1')
set(gca,'fontsize',12)
set(gca,'fontweight','bold')
box on


%[appendix]
%---
%[metadata:view]
%   data: {"layout":"onright"}
%---
