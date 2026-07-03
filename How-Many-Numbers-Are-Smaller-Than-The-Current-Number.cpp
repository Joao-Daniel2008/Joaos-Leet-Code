class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int tamanho = nums.size();
        vector<int> hash(101);
        for(int i = 0; i < tamanho; i++){
            hash[nums[i]]++;
        }
        int soma = 0;
        int indice = 0;
        int aux;
        for(int i = 0; i < 101; i++){
            if(hash[i] > 0){
                aux = hash[i];
                if (soma > 0){
                    hash[i] += soma;
                }
                soma += aux;

            }
        }
        int ultimo = 0;
        bool trocado = 0;
        int aux2;
        for(int i = 0; i < 101; i++){
            if(hash[i] - ultimo > 1 && hash[i] != 0){
                aux2 = ultimo;
                ultimo = hash[i];
                hash[i] = aux2 + 1;
                trocado = 1;
            }


            if(hash[i] > 0 && !trocado){
                ultimo = hash[i];
            } else if(trocado){
                trocado = 0;
            }
        }


        vector<int> lista(tamanho);
        ultimo = -1;
        for(int i = 0; i < tamanho; i++){
            lista[i] = hash[nums[i]] - 1;
        }
        
        return lista;
    }
};