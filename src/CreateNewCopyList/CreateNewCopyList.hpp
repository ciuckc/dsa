//
// Created by scristia on 25-10-24.
//

#ifndef CREATENEWCOPYLIST_HPP
#define CREATENEWCOPYLIST_HPP
#include <unordered_map>
#include <vector>

// I should ve made a mapping of old node to new node
// Then go through each old node in the list
// The random value of the new one would be to index
//  in the map with the old random value and get the address of that one,
//  which we find when we index
// Basically for each [k, v] pair
// v->random = map[k->random].second;
// Way easier than what I did


class CreateNewCopyList
{
public:
    class Node
    {
    public:
        int val;
        Node* next;
        Node* random;

        Node(int _val)
        {
            val = _val;
            next = nullptr;
            random = nullptr;
        }
    };

    void assignNodeIndexMap(Node* head, std::unordered_map<Node*, int>& node_to_index)
    {
        Node* current_head = head;

        for (auto i = 0; current_head != nullptr; ++i, current_head = current_head->next)
        {
            node_to_index.insert({current_head, i});
        }
    }

    Node* createNewCopyList(Node* head)
    {
        Node* new_head = nullptr;
        Node* current_node = head;
        Node* prev_node = nullptr;
        while (current_node != nullptr)
        {
            auto new_node = new Node(current_node->val);
            if (new_node == nullptr)
            {
                return nullptr;
            }
            if (new_head == nullptr)
            {
                new_head = new_node;
            }
            if (prev_node != nullptr)
            {
                prev_node->next = new_node;
            }
            prev_node = new_node;
            current_node = current_node->next;
        }
        return nullptr;
    }

    Node* copyRandomList(Node* head)
    {
        std::unordered_map<Node*, int> node_to_index{};
        assignNodeIndexMap(head, node_to_index);
        auto new_list = createNewCopyList(head);
        std::vector<Node*> new_list_vector{};
        for (auto current_node = new_list; current_node != nullptr; current_node = current_node->next)
        {
            new_list_vector.push_back(current_node);
        }
        for (auto current_node = new_list; current_node != nullptr; current_node = current_node->next)
        {
            if (head->random == NULL)
            {
                continue;
            }
            auto original_random_node = head->random;
            if (auto it = node_to_index.find(original_random_node); it != node_to_index.end())
            {
                current_node->random = new_list_vector[it->second];
            }
        }
    }
};
#endif //CREATENEWCOPYLIST_HPP
