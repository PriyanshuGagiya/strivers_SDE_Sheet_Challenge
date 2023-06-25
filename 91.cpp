//not able to solve learnt from solution section
//https://www.codingninjas.com/studio/problems/lfu-cache_8230851?challengeSlug=striver-sde-challenge&leftPanelTab=1
class LFUCache {
  unordered_map<int, Node *> mp;
  unordered_map<int, List *> freqList;
  int minFreq, cap, currSize;

public:
  LFUCache(int capacity) {
    minFreq = 0;
    cap = capacity;
    currSize = 0;
  }

  void updateList(Node *node) {
    mp.erase(node->key);
    freqList[node->freq]->deleteNode(node);

    if (freqList[node->freq]->size == 0 or node->freq == minFreq)
      minFreq++;

    List *newList = new List();
    if (freqList.count(node->freq + 1))
      newList = freqList[node->freq + 1];

    node->freq += 1;
    newList->addNewNode(node);
    freqList[node->freq] = newList;
    mp[node->key] = node;
  }

  int get(int key) {
    if (mp.count(key)) {
      Node *node = mp[key];
      int x = node->val;
      updateList(node);
      return x;
    }
    return -1;
  }

  void put(int key, int value) {
    if (cap == 0)
      return;

    else if (mp.count(key)) {
      Node *node = mp[key];
      node->val = value;
      updateList(node);
    }

    else {
      if (currSize == cap) {
        List *list = freqList[minFreq];
        mp.erase(list->tail->prev->key);
        list->deleteNode(list->tail->prev);
        currSize--;
      }

      currSize++;
      minFreq = 1;

      List *list = new List();
      if (freqList.count(minFreq))
        list = freqList[minFreq];

      Node *newNode = new Node(key, value);
      list->addNewNode(newNode);
      freqList[minFreq] = list;
      mp[key] = newNode;
    }
  }
};
