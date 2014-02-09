/*
 given n points in metric space, find a pair of points with the smallest distance between them
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <climits>
#include <ctime>
#include <float.h>
using namespace std;

#define epsilon 0.0001
#define maxDist 100000.00;
struct Point
{
    double x;
    double y;
    Point(){};
    Point(double a, double b):x(a),y(b){};
};
set<Point> res;
bool isLess(const Point &A,const Point &B)
{
    return A.x<B.x; // for 2D data
 //   return A.y<B.y; // for 1D data
}

double Distance(Point &A, Point &B)
{
    double dist = sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
    return dist;
}

double CalcBetween(vector<Point> &points,int start, int middle,int end)
{
    double left=maxDist;
    double right=maxDist;
    Point A = points[middle];
    double dist;
    for(int i=start;i<=middle-1;i++)
    {
        dist = Distance(points[i], A);
        if(dist<=left)
        left = dist;
    }
    for(int i=middle+1;i<=end;i++)
    {
        dist = Distance(points[i], A);
        if(dist<=right)
        right = dist;
    }
    /* For 1D data
    if(middle-1>=start)
    left = Distance(A,points[middle-1]);
    if(middle+1<=end)
    right = Distance(A,points[middle+1]);*/
    return min(left,right);
}

double DivideAndConqur(vector<Point> &points,int start,int end)
{
    if(start==end)
    return maxDist;
    if(end-start==1)
    {
        return Distance(points[start],points[end]);
    }
    int mid = (start+end)/2;
    double left = DivideAndConqur(points,start,mid);
    double right = DivideAndConqur(points,mid+1,end);
    double middle = CalcBetween(points,start,mid,end);
    double r= min(min(left,right),middle);
    return r;   
}
double findMinDistPoints(vector<Point> &points)
{
    int S = points.size();
    sort(points.begin(),points.end(),isLess);
    return DivideAndConqur(points,0,S-1);
}

double BrutalForce(vector<Point> &points)
{
    int S = points.size();
    double res = maxDist;
    for(int i=0;i<S;i++)
    for(int j=i+1;j<S;j++)
    {
        double dist = Distance(points[i],points[j]);
        if(dist<=res)
        {
            res = dist;
        }
    }
    return res;
}

int main()
{
   int len = 20;
   set<Point> res;
   vector<Point> points(len);
   for(int i=0;i<len;i++)
   {
       int positive = rand()%2;
       positive = positive==0?-1:1;
       double y = positive * rand()%300+1;
       int positive2 = rand()%2;
       positive2 = positive2==0?-1:1;
       double x = positive2 * rand()%1000+1;
       points[i] = Point(x,y);
       cout<<points[i].x<<","<<points[i].y<<endl;
   }
   double dist = findMinDistPoints(points);
   double dist2 = BrutalForce(points);
   cout<<"Minimum Dist @1= "<< dist<<endl;
   cout<<"Minimum Dist @2= "<< dist2<<endl;
   return 0;
}
