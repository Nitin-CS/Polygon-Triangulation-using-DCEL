//Nitin Chandra Surapur, 2018A7PS0188H
//R Venkat Srinik, 2018A7PS0266H
//Praneeth Pullela, 2018A7PS0257H


#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <cstring>
#include "dcel.h"

using namespace std;

int main(){
    //set up a face for all outer edges
    face outside;outside.face_id = -99;
    //Below is a DCEL with inner edges in counter clockwise
    int i;
    int num_points;
    float x,y;
    cin>>num_points;
    for(i=0;i<num_points;i++){
        cin>>x>>y;
        add_vertex(x,y);//v_count increased
        if(v_count == 2){
            add_edge(v_record[v_count-2],v_record[v_count-1]);//e_count increased
            add_face(e_record[e_count-1]);//f_count increased
            add_edge_and_twin_setup(v_record[v_count-1],v_record[v_count-2],e_record[e_count-1],&outside);//e_count increased
        }
        if(v_count > 2){
            add_edge_and_previous_setup(v_record[v_count-2],v_record[v_count-1],e_record[e_count-2],f_record[0]);//e_count increased
            add_edge_and_twin_setup(v_record[v_count-1],v_record[v_count-2],e_record[e_count-1],&outside);//e_count increased
        }
    }
    add_edge_and_previous_setup(v_record[v_count-1],v_record[0],e_record[e_count-2],f_record[0]);//e_count increased
    add_edge_and_twin_setup(v_record[0],v_record[v_count-1],e_record[e_count-1],&outside);//e_count increased

    e_record[0]->previous_edge = e_record[e_count-2];
    e_record[e_count-2]->next_edge = e_record[0];

    //print faces
    cout << "------------------------\nFACES\n";
    for(i=0;i<f_count;i++){
        cout << "face id:" << f_record[i]->face_id << " | starting edge:" << f_record[i]->start->origin->x << "," << f_record[i]->start->origin->y  << " to " << f_record[i]->start->next->x << "," << f_record[i]->start->next->y << "\n";
    }
    cout << "------------------------\nEDGES\n";
    //print edges
    for(i=0;i<e_count;i++){
        cout<< "\tEdge id = " << e_record[i]->edge_id<< "\tstart = " << e_record[i]->origin->x << "," << e_record[i]->origin->y << " | next = " << e_record[i]->next->x << "," << e_record[i]->next->y << "\n";
    }
    cout << "------------------------\nVERTICES\n";
    for(i=0;i<v_count;i++){
        cout << "\t\tVertex id:" << v_record[i]->id << " | coordinates:" << v_record[i]->x << "," << v_record[i]->y << "\n";
    }

    if(v_count>0 && e_count>0 && f_count>0)
        cout<<"Done.Success.\n";

    y_monotone();

    cout<<"Result of y monotone:\n\n\n";

    cout << "------------------------\nFACES\n";
    for(i=0;i<f_count;i++){
        cout << "face id:" << f_record[i]->face_id << " | starting edge:" << f_record[i]->start->origin->x << "," << f_record[i]->start->origin->y  << " to " << f_record[i]->start->next->x << "," << f_record[i]->start->next->y << "\n";

    }
    cout << "------------------------\nEDGES\n";
    //print edges
    for(i=0;i<e_count;i++){
        cout<< "\tEdge id = " << e_record[i]->edge_id<< "\tstart = " << e_record[i]->origin->x << "," << e_record[i]->origin->y << " | next = " << e_record[i]->next->x << "," << e_record[i]->next->y << "\n";
    }
    cout << "------------------------\nVERTICES\n";
    for(i=0;i<v_count;i++){
        cout << "\t\tVertex id:" << v_record[i]->id << " | coordinates:" << v_record[i]->x << "," << v_record[i]->y << "\n";
    }

    if(v_count>0 && e_count>0 && f_count>0)
        cout<<"Done.Success.\n";

    for(i=0;i<f_count;i++){
        triangulate(f_record[i]);
    }

    cout<<"Result of triangulate:\n\n\n";

    cout << "------------------------\nFACES\n";
    for(i=0;i<f_count;i++){
        cout << "face id:" << f_record[i]->face_id << " | starting edge:" << f_record[i]->start->origin->x << "," << f_record[i]->start->origin->y  << " to " << f_record[i]->start->next->x << "," << f_record[i]->start->next->y << "\n";

    }
    cout << "------------------------\nEDGES\n";
    //print edges
    for(i=0;i<e_count;i++){
        cout<< "\tEdge id = " << e_record[i]->edge_id<< "\tstart = " << e_record[i]->origin->x << "," << e_record[i]->origin->y << " | next = " << e_record[i]->next->x << "," << e_record[i]->next->y << "\n";
    }
    cout << "------------------------\nVERTICES\n";
    for(i=0;i<v_count;i++){
        cout << "\t\tVertex id:" << v_record[i]->id << " | coordinates:" << v_record[i]->x << "," << v_record[i]->y << "\n";
    }

    if(v_count>0 && e_count>0 && f_count>0)
        cout<<"Done.Success.\n";

    return 0;
}
