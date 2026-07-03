class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int tamanho = nums.size();
        vector<int> hash(tamanho + 1);
        for(int i = 0; i < tamanho; i++){
            hash[nums[i]]++;
        }
        vector<int> lista;
        for(int i = 1; i < tamanho + 1; i++){
            if(hash[i] == 0){
                lista.push_back(i);
            }
        }
        return lista;
    }
};