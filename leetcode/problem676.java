class MagicDictionary {
    class Node {
        Node[] children = new Node[26];
        boolean isEnd = false;

        void insert(String str, int idx) {
            if(idx == str.length()) {
                isEnd = true;
                return;
            }

            int childIdx = str.charAt(idx) - 'a';

            if(children[childIdx] == null) {
                children[childIdx] = new Node();
            }

            children[childIdx].insert(str, idx+1);
        }

        boolean search(String str, int idx, boolean isChanged) {
            if(idx == str.length()) {
                return isEnd && isChanged;
            }

            boolean ret = false;
            int childIdx = str.charAt(idx) - 'a';
            Node child = children[childIdx];

            if(child != null) {
                ret = child.search(str, idx+1, isChanged);
            }

            if(ret) return true;

            if(isChanged) return false;
            for (int i=0; i<26; ++i) {
                if(childIdx != i && children[i] != null) {
                    ret = children[i].search(str, idx + 1, true);
                    if(ret) break;
                }
            }

            return ret;
        }
    }
    private Node root;

    /** Initialize your data structure here. */
    public MagicDictionary() {
        root = new Node();
    }

    /** Build a dictionary through a list of words */
    public void buildDict(String[] dict) {
        for (String d : dict) {
            root.insert(d, 0);
        }
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    public boolean search(String word) {
        return root.search(word, 0, false);
    }
}

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * boolean param_2 = obj.search(word);
 */

