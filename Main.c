#include <stdio.h>
#include <stdlib.h>
#include<math.h>

/*R1 interchange with R2 function*/
int r1_r2(float a[3][3]){
    float temp[3][3];
    int i,j,x;
    for(i=0, x=1; i<=1 && x>=0; i++, x--){
		for(j=0; j<3; j++){
			temp[i][j]=a[x][j];
		}
	}

	for(i=0; i<=1; i++){
		for(j=0; j<3; j++){
			a[i][j]=temp[i][j];
		}
	}
    return a[3][3];
}

/*R1 interchange with R3 function*/
int r1_r3(float a[3][3]){
    float temp[3][3];
    int i,j,x;
    for(i=0, x=2; i<=2 && x>=0; i++, x--){
		for(j=0; j<3; j++){
			temp[i][j]=a[x][j];
		}
		i++;
		x--;
	}

    for(i=0; i<=2; i++){
		for(j=0; j<3; j++){
			a[i][j]=temp[i][j];
		}
		i++;
	}
    return a[3][3];
}

/*R2 interchange with R3 function*/
int r2_r3(float a[3][3]){
    float temp[3][3];
    int i,j,x;
	for(i=1, x=2; i<=2 && x>0; i++, x--){
		for(j=0; j<3; j++){
			temp[i][j]=a[x][j];
		}
	}

	for(i=1; i<3; i++){
		for(j=0; j<3; j++){
			a[i][j]=temp[i][j];
		}
	}
    return a[3][3];
}

int ech(float d[3][3]){
    int i, j;
    float b[3][3];
    /*Duplicate matrix*/
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            b[i][j]=d[i][j];
        }
    }

    for(i=0; i<3; i++){
        if(d[0][0]==0){
            if(d[1][0]!=0)
                r1_r2(d);
            else if(d[2][0]!=0)
                r1_r3(d);
        }
        if(d[1][0]==0&&d[1][1]==0&&d[2][0]==0&&d[2][1]!=0){
            r2_r3(d);
        }
        if(d[1][0]==0&&d[1][1]==0&&d[2][0]!=0&&d[2][1]!=0){
            r2_r3(d);
        }
    }

    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            b[i][j]=d[i][j];
        }
    }

    row2:
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            b[i][j]=d[i][j];
        }
    }

    if(d[1][0]!=0){
        for(i=0; i<1; i++){
            if((b[i][0]>0 && b[i+1][0]>0)||(b[i][0]<0 && b[i+1][0]<0)){
                for(j=0; j<3; j++){
                    d[i+1][j]=((b[i+1][j] * b[0][0]) - (b[0][j]*b[i+1][0]));
                }
            }
            else{
                for(j=0; j<3; j++){
                    d[i+1][j]=((b[i+1][j] * b[0][0]) + (b[0][j]*b[i+1][0]));
                }
            }
        }
    }

    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            b[i][j]=d[i][j];
        }
    }

    if(d[0][0]==0){
        if(d[1][0]!=0)
            r1_r2(d);
        else if(d[2][0]!=0)
            r1_r3(d);
    }

    if(d[1][0]==0&&d[1][1]==0&&d[2][0]==0&&d[2][1]!=0){
        r2_r3(d);
    }

    if(d[1][0]==0&&d[1][1]==0&&d[2][0]!=0&&d[2][1]!=0){
        r2_r3(d);
    }

    if(d[2][0]!=0){
        for(i=0; i<1; i++){
            if((b[i][0]>0 && b[i+2][0]>0)||(b[i][0]<0 && b[i+2][0]<0)){
                for(j=0; j<3; j++){
                    d[i+2][j]=((b[i+2][j] * b[0][0]) - (b[0][j]*b[i+2][0]));
                }
            }
            else{
                for(j=0; j<3; j++){
                    d[i+2][j]=((b[i+2][j] * b[0][0]) + (b[0][j]*b[i+2][0]));
                }
            }
        }
    }

    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            b[i][j]=d[i][j];
        }
    }

    if(d[0][0]==0){
        if(d[1][0]!=0)
            r1_r2(d);
        else if(d[2][0]!=0)
            r1_r3(d);
    }

    if(d[1][0]==0&&d[1][1]==0&&d[2][0]==0&&d[2][1]!=0){
        r2_r3(d);
    }

    if(d[1][0]==0&&d[1][1]==0&&d[2][0]!=0&&d[2][1]!=0){
        r2_r3(d);
    }

    row3:
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            b[i][j]=d[i][j];
        }
    }

    if(d[2][1]!=0){
        for(i=1; i<2; i++){
            if((b[i][1]>0 && b[i+1][1]>0)||(b[i][1]<0 && b[i+1][1]<0)){
                for(j=0; j<3; j++){
                    d[i+1][j]=((b[i+1][j] * b[1][1]) - (b[i][j]*b[2][1]));
                }
            }
            else{
                for(j=0; j<3; j++){
                    d[i+1][j]=((b[i+1][j] * b[1][1]) + (b[i][j]*b[2][1]));
                }
            }
        }
    }

    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            b[i][j]=d[i][j];
        }
    }

    if(d[2][0]==0 && d[2][1]==0 && d[2][2]!=0){
        for(i=1; i<2; i++){
            if((b[i][1]>0 && b[i+1][1]>0)||(b[i][1]<0 && b[i+1][1]<0)){
                for(j=0; j<3; j++){
                    d[i+1][j]=((b[i+1][j] * b[1][1]) - (b[i][j]*b[2][1]));
                }
            }
            else{
                for(j=0; j<3; j++){
                    d[i+1][j]=((b[i+1][j] * b[1][1]) + (b[i][j]*b[2][1]));
                }
            }
        }
    }

    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            b[i][j]=d[i][j];
        }
    }

    if(d[0][0]==0){
        if(d[1][0]!=0)
            r1_r2(d);
        else if(d[2][0]!=0)
            r1_r3(d);
    }

    if(d[1][0]==0&&d[1][1]==0&&d[2][0]==0&&d[2][1]!=0){
        r2_r3(d);
    }

    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            b[i][j]=d[i][j];
        }
    }

    if(d[1][0]==0&&d[1][1]==0&&d[2][0]!=0&&d[2][1]!=0){
        r2_r3(d);
    }

    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            b[i][j]=d[i][j];
        }
    }

    if(d[1][0]==0&&d[1][1]!=0&&d[1][2]!=0&&d[2][0]!=0&&d[2][1]==0&&d[2][2]!=0){
        r2_r3(d);
    }

    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            b[i][j]=d[i][j];
        }
    }

    if(d[1][0]!=0){
        goto row2;
    }

    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            b[i][j]=d[i][j];
        }
    }

    if((d[2][0]!=0)||(d[2][1]!=0)){
        goto row3;
    }

    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            b[i][j]=d[i][j];
        }
    }
    return d[3][3];
}

void main(){
    int i, j, r, w1, v;
    float a[3][3], d[3][3];
    double det=0, b1, c1, d1, e1, f1, g1, h1, i1, j1, k1, l1, m1, n1, p1, r1, s1, t1, u1, o, x1, x2, x3, a1=1, v1, v2, v3, rk;
    printf("Enter the matrix elements:");

    /*Taking array as input from user*/
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            printf("\n Enter the Array a[%d][%d]: ",i,j);
            scanf("%f",&a[i][j]);
        }
    }

    /*Duplicate matrix*/
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            d[i][j]=a[i][j];
        }
    }

    /* Display array contents */
    printf("\nThe entered matrix: \n");
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            printf(" %.6g ", a[i][j]);
        }
        printf("\n");
    }

    /* Finding roots */
    b1=(-1)*(a[0][0]+a[1][1]+a[2][2]);

    c1=((a[1][1]*a[2][2])-(a[2][1]*a[1][2])) + ((a[0][0]*a[2][2])- (a[2][0]*a[0][2])) + ((a[0][0]*a[1][1])-(a[1][0]*a[0][1]));

    det=a[0][0]*( (a[1][1]*a[2][2])-(a[2][1]*a[1][2])) - a[0][1]*((a[1][0]*a[2][2])- (a[2][0]*a[1][2])) + a[0][2]*((a[1][0]*a[2][1])-(a[2][0]*a[1][1]));

    d1=(-1)*det;

    e1=2.7182818284590;

    f1=((3*c1/a1)-(b1*b1/(a1*a1)))/3;

    g1=((2*b1*b1*b1/(a1*a1*a1))-(9*b1*c1/(a1*a1))+(27*d1/a1))/27;

    h1=(g1*g1/4)+(f1*f1*f1/27);

    i1=sqrt(((g1*g1/4)-h1));

    j1=exp(log10(i1)/log10(e1)/3);

    k1=acos((-1)*(g1/(2*i1)));

    l1=j1*(-1);

    m1=cos(k1/3);

    n1=sqrt(3)*sin(k1/3);

    p1=(b1/3*a1)*(-1);

    r1=(-1)*(g1/2)+sqrt(h1);

    s1=exp(log10(r1)/log10(e1)/3);

    t1=(-1)*(g1/2)-sqrt(h1);

    u1=exp(log10(t1)/log10(e1)/3);

    if (h1>0)
        w1=1;

    if (h1<=0)
        w1=3;

    if ((f1==0) && (g1==0) && (h1==0))
        w1=2;

    printf("\nCharacteristics Equation: ƛ³ + (%.6g)ƛ²+ (%.6g)ƛ + (%.6g) = 0",b1, c1, d1);

    switch (w1){
        case 1:
            x1=(s1+u1)-(b1/3*a1);
            x2=(-1)*(s1+u1)/2-(b1/3*a1);
            x3=(s1-u1)*sqrt(3)/2;
            printf("\nEigen Values : %.6g,%.6g,%.6g", x1, x2, x3);
            break;
        case 2:
            x1=exp(log10(d1/a1)/log10(e1)/3)*(-1);
            printf("\nEigen values : %.6g", x1);
            break;
        case 3:
            x1=2*j1*cos(k1/3)-(b1/3*a1);
            x2=l1*(m1+n1)+p1;
            x3=l1*(m1-n1)+p1;
            printf("\nEigen Values : %.6g, %.6g, %.6g", x1, x2, x3);
            break;
    }
    for(r=0; r<3; r++){
        if(r==0){
            v = x1;
        }

        if(r==1){
            v = x2;
        }

        if(r==2){
            v = x3;
        }
        printf("\n====================================================================\n");
        printf("\nCase %d: ƛ = %d \n", r+1,v);
        for(i=0; i<3; i++){
            for(j=0; j<3; j++){
                if(i==j)
                    d[i][j] = a[i][j] - v;
            }
        }

        /* Display array contents */
        printf("\nCharacteristics matrix:\n");
        for(i=0; i<3; i++){
            for(j=0; j<3; j++){
                printf(" %.6g ", d[i][j]);
            }
            printf("\n");
        }

        ech(d);

        /* Display array contents */
        printf("\nEchelon form: \n");
        for(i=0; i<3; i++){
            for(j=0; j<3; j++){
                printf(" %.6g ", d[i][j]);
            }
            printf("\n");
        }

        /* Finding Rank of echelon form */
        if(d[1][0]==0 && d[2][0]==0 && d[2][1]==0)
            rk = 3.0;

        if(d[1][0]==0 && d[2][0]==0 && d[2][1]==0 && d[2][2]==0)
            rk = 2.0;

        if(d[1][0]==0 && d[1][1]==0 && d[1][2]==0 && d[2][0]==0 && d[2][1]==0 && d[2][2]==0)
            rk = 1.0;

        printf("\nThe rank for case %d: %.6g", r+1, rk);

        /* For rank=3 */
        if(rk==3){
            v1 = d[2][2];
            v2 = ((-1)*d[1][2]*d[2][2])/d[1][1];
            v3 = ((d[0][1]*d[1][2]*d[2][2]) - (d[0][2]*d[1][1]*d[2][2]))/(d[0][0]*d[1][1]);
            printf("\nThe Eigen Vector X%d: ",r+1);
            printf("\n%.6gt", v3);
            printf("\n%.6gt", v2);
            printf("\n%.6gt", v1);
        }

        /* For rank=2 */
        if(rk==2){
            v1 = 1;
            v2 = ((-1.0)*d[1][2])/(d[1][1]);
            v3 = ((d[0][1]*v2*(-1)) - (d[0][2]))/(d[0][0]);
            printf("\nThe Eigen Vector X%d: ",r+1);
            printf("\n%.6gt", v3);
            printf("\n%.6gt", v2);
            printf("\n1t");
        }

        /* For rank=1 */
        if(rk==1){
            v1 = (-1)*d[0][1];
            v2 = (-1)*d[0][2];
            v3 = d[0][0];
            printf("\nThe Eigen Vector X%d: ",r+1);
            printf("\n (%.6gt2 + %.6gt1)/%.6g",v1, v2, v3);
            printf("\nt2");
            printf("\nt1");
        }

        /*Duplicate matrix*/
        for(i=0; i<3; i++){
            for(j=0; j<3; j++){
                d[i][j]=a[i][j];
            }
        }
    }
}
