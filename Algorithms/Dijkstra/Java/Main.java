package Algorithms.Dijkstra.Java;

import java.util.*;
public class Main{
    public static ArrayList <Integer> dijkstra(double graph[][], int origin, int destination){
        int n = graph.length;
        double distances[] = new double[n];
        for(int i = 0; i < n; i++){
            distances[i] = Double.POSITIVE_INFINITY;
        }
        distances[origin] = 0;
        int previous[] = new int[n];
        for(int i = 0; i < n; i++){
            previous[i] = -1;
        }
        boolean visited[] = new boolean[n];
        for(int i = 0; i < n - 1; i++){
            int minDistanceLoc = -1;
            double minDistance = Double.POSITIVE_INFINITY;
            for(int j = 0; j < n; j++){
                if(!visited[j] && distances[j] < minDistance){
                    minDistance = distances[j];
                    minDistanceLoc = j;
                }
            }
            if(minDistanceLoc == -1){
                break;
            }
            visited[minDistanceLoc] = true;
            for(int j = 0; j < n; j++){
                double edgeWeight = graph[minDistanceLoc][j];
                if(edgeWeight != 0 && !visited[j]){
                    double newDistance = distances[minDistanceLoc] + edgeWeight;
                    if(distances[j] > newDistance){
                        distances[j] = newDistance;
                        previous[j] = minDistanceLoc;
                    }
                }
                
            }
        }
        if(previous[destination] != -1){
            ArrayList<Integer> route = new ArrayList<>();
            Stack<Integer> preRouteStack = new Stack<>();
            int node = destination;
            while(node != -1){
                preRouteStack.push(node);
                node = previous[node];
            }
            while(!preRouteStack.empty()){
                route.add(preRouteStack.pop());
            }
            return route;
        }
        return null;
    }
    public static void main(String[] args) {
        double[][] graph = {{0, 2, 4, 0, 2, 0, 0, 0},
                            {2, 0, 0, 0, 0, 0, 0, 6},
                            {4, 0, 0, 0, 0, 0, 0, 3},
                            {0, 0, 0, 0, 1.5, 0, 0, 3},
                            {2, 0, 0, 1.5, 0, 2, 2, 0},
                            {0, 0, 0, 0, 2, 0, 1, 0, 3},
                            {0, 0, 0, 0, 0, 1, 0, 3},
                            {0, 6, 3, 3, 0, 0, 3, 0}};
        ArrayList<Integer> route = dijkstra(graph, 0, 7);
        for(int i = 0; i < route.size(); i++){
            System.out.print(route.get(i));
            if(i < route.size() - 1){
                System.out.print(" --> ");
            }
        }
        System.out.println();
    }
}