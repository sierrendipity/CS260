#include "graph.hpp"
#include "test.hpp"

int main() {
    Graph g;
    int choice;

    std::cout << "\nWELCOME TO PENGUIN EXPLORER\n";

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add an iceberg (vertex)\n";
        std::cout << "2. Add a fishing path (edge)\n";
        std::cout << "3. Find shortest path between icebergs\n";
        std::cout << "4. Find MST\n";
        std::cout << "5. Display Graph\n";
        std::cout << "6. Test\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";
        
        // Validate input
        while (!(std::cin >> choice) || choice < 1 || choice > 7) {
            std::cout << "Invalid input. Please enter a number between 1 and 7: ";
            std::cin.clear(); // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        }

        switch (choice) {
            case 1: {
                g.AddVertex();
                break;
            }
            case 2: {
                std::string from, to;
                int weight;
                std::cout << "Enter source iceberg name: ";
                std::cin >> from;
                std::cout << "Enter destination iceberg name: ";
                std::cin >> to;
                std::cout << "Enter distance (1-40 miles): ";
                std::cin >> weight;
                g.AddEdge(from, to, weight);
                break;
            }
            case 3: {
                std::string src, dest;
                std::cout << "Enter source iceberg name: ";
                std::cin >> src;
                std::cout << "Enter destination iceberg name: ";
                std::cin >> dest;
                g.ShortestPath(src, dest);
                break;
            }
            case 4: {
                g.MinSpanTree();
                break;
            }
            case 5: {
                g.DisplayGraph();
                break;
            }
            case 6: {
                std::cout << "Running Graph Tests:\n";
                GraphTest graphTest;
                bool allTestsPassed = true;
                allTestsPassed &= graphTest.TestAddVertex1();
                allTestsPassed &= graphTest.TestAddVertex2();
                allTestsPassed &= graphTest.TestAddEdge1();
                allTestsPassed &= graphTest.TestAddEdge2();
                allTestsPassed &= graphTest.TestShortestPath1();
                allTestsPassed &= graphTest.TestShortestPath2();
                allTestsPassed &= graphTest.TestMinSpanTree1();
                allTestsPassed &= graphTest.TestMinSpanTree2();
                if (allTestsPassed)
                    std::cout << "All Tests Passed Successfully!\n";
                else
                    std::cout << "Some Tests Failed!\n";
                break;
            }
            case 7:
                std::cout << "Exiting. Thank you! \n";
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}

