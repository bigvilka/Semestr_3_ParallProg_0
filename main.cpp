#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

class Graph
{
    int number_of_points, **matrix;
    vector<int> check;
public:
    Graph(int inp_number_of_points)
    {
        this->number_of_points = inp_number_of_points;
        matrix = new int* [this->number_of_points];
        for (int i = 0; i < this->number_of_points; i++)
        {
            matrix[i] = new int[this->number_of_points];
            for (int j = 0; j < this->number_of_points; j++)
                matrix[i][j] = 0;

            cout << "¬ведите количество смежных вершин дл€ вершины " << i << endl;
            int size_of_neigh;
            cin >> size_of_neigh;
            cout << "¬ведите нормера смежных вершин дл€ вершины " << i << endl;

            for (int j = 0; j < size_of_neigh; j++)
            {
                int neigh;
                cin >> neigh;
                matrix[i][neigh] = 1;
            }
        }
    }

    void Print(Graph *graph)
    {
        for (int i = 0; i < graph->number_of_points; i++)
        {
            for (int j = 0; j < graph->number_of_points; j++)
            {
                cout << graph->matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void WalkWide(Graph *graph, int head)
    {
        int last;
        //обходит первую вершину
        if (check.size() == 0)
        {
            cout << head << " ";
            check.push_back(head);
        }

        for (int j = 0; j < graph->number_of_points; j++)
        {
            if (graph->matrix[head][j] == 1)
            {
                bool checked = false;
                for (int i = 0; i < check.size(); i++)
                {
                    if (j == check.at(i))
                        checked = true;
                }

                if (checked == false)
                {
                    check.push_back(j);
                    cout << j << " ";
                    last = j;
                }
            }

        }

        //обошли все вершины?
        if (check.size() != graph->number_of_points)
            WalkWide(graph, last);
            else
                check.clear();
    }

    void WalkDeep(Graph *graph, int head)
    {
        int last;
        bool get_point = false;
        //обходит первую вершину
        if (check.size() == 0)
        {
            cout << head << " ";
            check.push_back(head);
        }

        for (int j = 0; j < graph->number_of_points; j++)
        {
            if (graph->matrix[head][j] == 1 && get_point == false)
            {
                bool checked = false;
                for (int i = 0; i < check.size(); i++)
                {
                    if (j == check.at(i))
                        checked = true;
                }

                if (checked == false)
                {
                    check.push_back(j);
                    cout << j << " ";
                    last = j;
                    get_point = true;
                }
            }
        }

        if (check.size() != graph->number_of_points)
            WalkDeep(graph, last);
            else
                check.clear();
    }
};

int main()
{
    setlocale(0, "Russian");
    freopen("test.txt", "r", stdin);

    cout << "¬ведите количество вершин графа" << endl;
    int number_of_points;
    cin >> number_of_points;

    Graph graph(number_of_points);
    graph.Print(&graph);

    cout << "ќбход в ширину:" << endl;
    graph.WalkWide(&graph, 0);

    cout << endl << "ќбход в глубину:" << endl;
    graph.WalkDeep(&graph, 0);

    freopen("CONIN$", "r", stdin);
    return 0;
}
