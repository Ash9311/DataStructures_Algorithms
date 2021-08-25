void printSubset(vector<int> input,vector<int> output, int i){
    if(i>=input.size()){
        for(auto i: output){
            cout<<i<<" ";
        }
        cout<<endl;
        totalSubset++;
        return;
    }
    printSubset(input,output,i+1);

    output.push_back(input[i]);
    printSubset(input,output,i+1);
}
