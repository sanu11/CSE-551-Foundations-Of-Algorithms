public class MatrixMultiplicationCost {

    public int findCost(int arr[]){
        int temp[][] = new int[arr.length][arr.length];
        int q = 0;
        for(int l=2; l < arr.length; l++){
            System.out.println("first loop"+l);
            for(int i=0; i < arr.length - l; i++){
                int j = i + l;

            System.out.println("second loop i,j="+i+" "+j);
                temp[i][j] = 1000000;
                for(int k=i+1; k < j; k++){

            
                    q = temp[i][k] + temp[k][j] + arr[i]*arr[k]*arr[j];
                    if(q < temp[i][j]){
                        temp[i][j] = q;
                    }
                    System.out.println("third loop k,temp[i][j]"+k+" "+temp[i][j]);
                }
            }
        }
        return temp[0][arr.length-1];
    }
    
    public static void main(String args[]){
        MatrixMultiplicationCost mmc = new MatrixMultiplicationCost();
        int arr[] = {4,2,3,5,3};
        int cost = mmc.findCost(arr);
        System.out.print(cost);
    }
}