#include<iostream>
#include<cstdlib>
using namespace std;
struct Text56{
	char val[56];
};
struct Text48{
	char val[48];
};
struct Text32{
	char val[32];
};
Text56 Key[17];
Text32 L[17];
Text32 R[17];
char XOR(char a, char b){
	if(a == b) return '0';
	else return '1';
}
int BIN2DEC(char a, char b){
	int count = 0;
	if(b == '1') count += 1;
	if(a == '1') count += 2;
	return count;
}
int BIN4DEC(char a, char b, char c, char d){
	int count = 0;
	if(d == '1') count += 1;
	if(c == '1') count += 2;
	if(b == '1') count += 4;
	if(a == '1') count += 8;
	return count;
}

int main(){
	int i, j , k;
	string plain_text, key;
	plain_text = "0000000100100011010001010110011110001001101010111100110111101111";
	key = "0001001100110100010101110111100110011011101111001101111111110001";
	
//	cin>>plain_text
//	cin>>key;
	//Step 1: Create 16 subkeys, each of which is 48-bits long.
	//Step 1. Permutasi PC1 pada Key
	cout<<"Step 1. Permutasi PC1 pada Key"<<endl;
	char pc1[56];
    
	k = 57;
    for(i = 0 ; i < 28 ; i++){
        pc1[i] = key[k-1];
        if(k-8>0)    k=k-8;
        else      k=k+57;
    }
    k = 63;
    for(i = 28 ; i < 52 ; i++){
        pc1[i] = key[k-1];
        if(k-8>0)    k=k-8;
        else         k=k+55;
    }
    k = 28;
    for(i = 52 ; i < 56 ; i++){
        pc1[i] = key[k-1];
        k=k-8;
    }

	cout<<"Key (64 bit) = "<<key<<endl<<"Key'(56 bit) =";
    for(i = 0 ; i < 56 ; i++){
    	if(i%7==0){
    		cout<<" "<<pc1[i];
    	}else{
    		cout<<pc1[i];
    	}
    	
    }
	cout<<endl;
	system("pause");
	system("cls");
	//Step 2. Membuat Key C0 dan D0 hingga C16 dan D16
	cout<<"Step 2. Membuat C0 dan D0 hingga C16 dan D16"<<endl;
	int no_shift = 0;
	for(i = 0 ; i <= 16 ; i++){
		if(i == 0) no_shift = 0;
		else if(i == 1 || i== 2 || i== 9 || i == 16) no_shift = 1;
		else no_shift = 2;
		
		if(i == 0){
			for(j = 0 ; j < 56 ; j++){
				Key[0].val[j] = pc1[j];
			}
			//C ke 0
			cout<<"C"<<i<<" =";
			for(k = 0 ; k < 28 ; k++){
				if(k%7 == 0) cout<<" "<<Key[0].val[k];
				else cout<<Key[0].val[k];
			}
			cout<<endl;
			//D ke 0
			cout<<"D"<<i<<" =";
			for(k = 28 ; k < 56 ; k++){
				if(k%7 == 0) cout<<" "<<Key[0].val[k];
				else cout<<Key[0].val[k];
			}
			cout<<endl;
		}else{
			for(j = 0 ; j < 28-no_shift ; j++){
				Key[i].val[j] = Key[i-1].val[j+no_shift];
			}
			k = 0;
			for(j = 28-no_shift ; j < 28 ; j++){
				Key[i].val[j] = Key[i-1].val[k++];
			}
			for(j = 28 ; j < 56-no_shift ; j++){
				Key[i].val[j] = Key[i-1].val[j+no_shift];
			}
			k = 28;
			for(j = 56-no_shift ; j < 56 ; j++){
				Key[i].val[j] = Key[i-1].val[k++];
			}
			//C ke i
			cout<<"C"<<i<<" =";
			for(k = 0 ; k < 28 ; k++){
				if(k%7 == 0) cout<<" "<<Key[i].val[k];
				else cout<<Key[i].val[k];
			}
			cout<<endl;
			//D ke i
			cout<<"D"<<i<<" =";
			for(k = 28 ; k < 56 ; k++){
				if(k%7 == 0) cout<<" "<<Key[i].val[k];
				else cout<<Key[i].val[k];
			}
			cout<<endl;
		}
	}
	cout<<endl;
	system("pause");
	system("cls");
	
	//Step 3. Permutasi PC2 pada Key
	cout<<"Step 3. Permutasi PC2 pada Key"<<endl;
	for(i = 1 ; i <= 16 ; i++){
		char temp[56];
		for(j = 0 ; j < 56 ; j++){
			temp[j] = Key[i].val[j];
		}
		Key[i].val[0] = temp[13];
	    Key[i].val[1] = temp[16];
	    Key[i].val[2] = temp[10];
	    Key[i].val[3] = temp[23];
	    Key[i].val[4] = temp[0];
	    Key[i].val[5] = temp[4];
	    Key[i].val[6] = temp[2];
	    Key[i].val[7] = temp[27];
	    Key[i].val[8] = temp[14];
	    Key[i].val[9] = temp[5];
	    Key[i].val[10] = temp[20];
	    Key[i].val[11] = temp[9];
	    Key[i].val[12] = temp[22];
	    Key[i].val[13] = temp[18];
	    Key[i].val[14] = temp[11];
	    Key[i].val[15] = temp[3];
	    Key[i].val[16] = temp[25];
	    Key[i].val[17] = temp[7];
	    Key[i].val[18] = temp[15];
	    Key[i].val[19] = temp[6];
	    Key[i].val[20] = temp[26];
	    Key[i].val[21] = temp[19];
	    Key[i].val[22] = temp[12];
	    Key[i].val[23] = temp[1];
	    Key[i].val[24] = temp[40];
	    Key[i].val[25] = temp[51];
	    Key[i].val[26] = temp[30];
	    Key[i].val[27] = temp[36];
	    Key[i].val[28] = temp[46];
	    Key[i].val[29] = temp[54];
	    Key[i].val[30] = temp[29];
	    Key[i].val[31] = temp[39];
	    Key[i].val[32] = temp[50];
	    Key[i].val[33] = temp[46];
	    Key[i].val[34] = temp[32];
	    Key[i].val[35] = temp[47];
	    Key[i].val[36] = temp[43];
	    Key[i].val[37] = temp[48];
	    Key[i].val[38] = temp[38];
	    Key[i].val[39] = temp[55];
	    Key[i].val[40] = temp[33];
	    Key[i].val[41] = temp[52];
	    Key[i].val[42] = temp[45];
	    Key[i].val[43] = temp[41];
	    Key[i].val[44] = temp[49];
	    Key[i].val[45] = temp[35];
	    Key[i].val[46] = temp[28];
	    Key[i].val[47] = temp[31];
	}
	
	for(i = 1 ; i <= 16 ; i++){
		cout<<"K"<<i<<" =";
		for(j = 0 ; j < 48 ; j++){
			if(j%6 == 0) cout<<" "<<Key[i].val[j];
			else cout<<Key[i].val[j];
		}
		cout<<endl;
	}
	cout<<endl;
	system("pause");
	system("cls");
	
	//Step 4. Permutasi IP pada Plain Text
	cout<<"Step 4. Mencari R0"<<endl;
	char temp[64];
	
    k = 58;
    for(i = 0 ; i < 32 ; i++){
        temp[i] = plain_text[k-1];
        if(k-8>0)    k=k-8;
        else      k=k+58;
    }
    k = 57;
    for(i = 32 ; i <64 ; i++){
        temp[i] = plain_text[k-1];
        if(k-8>0)    k=k-8;
        else      k=k+58;
    }
    
    for(i = 0 ; i < 32 ; i++){
    	L[0].val[i] = temp[i];
    }
    for(i = 32 ; i < 64 ; i++){
    	R[0].val[i-32] = temp[i];
    }
    cout<<"L0\t\t=";
	for(i = 0 ; i < 32 ; i++){
		if(i%4 ==0) cout<<" "<<L[0].val[i];
		else cout<<L[0].val[i];
	}
	cout<<endl;
	cout<<"R0\t\t=";
	for(i = 0 ; i < 32 ; i++){
		if(i%4 ==0) cout<<" "<<R[0].val[i];
		else cout<<R[0].val[i];
	}
	
	cout<<endl;
	for(i = 1 ; i <= 16 ; i++){
		//Membuat L ke i
		for(j = 0 ; j < 32 ; j++){
			L[i].val[j] = R[i-1].val[j];
		}
		
		//Step5. Expansion Table
		Text48 ER;
		for(j = 0 ; j < 48 ; j++){
			ER.val[j] = '0';
		}
 		ER.val[0] = R[i-1].val[31];
		ER.val[1] = R[i-1].val[0];
		ER.val[2] = R[i-1].val[1];
		ER.val[3] = R[i-1].val[2];
		ER.val[4] = R[i-1].val[3];
		ER.val[5] = R[i-1].val[4];
		
		ER.val[6] = R[i-1].val[3];
		ER.val[7] = R[i-1].val[4];
		ER.val[8] = R[i-1].val[5];
		ER.val[9] = R[i-1].val[6];
		ER.val[10] = R[i-1].val[7];
		ER.val[11] = R[i-1].val[8];
		
		ER.val[12] = R[i-1].val[7];
		ER.val[13] = R[i-1].val[8];
		ER.val[14] = R[i-1].val[9];
		ER.val[15] = R[i-1].val[10];
		ER.val[16] = R[i-1].val[11];
		ER.val[17] = R[i-1].val[12];
		
		ER.val[18] = R[i-1].val[11];
		ER.val[19] = R[i-1].val[12];
		ER.val[20] = R[i-1].val[13];
		ER.val[21] = R[i-1].val[14];
		ER.val[22] = R[i-1].val[15];
		ER.val[23] = R[i-1].val[16];
		
		ER.val[24] = R[i-1].val[15];
		ER.val[25] = R[i-1].val[16];
		ER.val[26] = R[i-1].val[17];
		ER.val[27] = R[i-1].val[18];
		ER.val[28] = R[i-1].val[19];
		ER.val[29] = R[i-1].val[20];
		
		ER.val[30] = R[i-1].val[19];
		ER.val[31] = R[i-1].val[20];
		ER.val[32] = R[i-1].val[21];
		ER.val[33] = R[i-1].val[22];
		ER.val[34] = R[i-1].val[23];
		ER.val[35] = R[i-1].val[24];
		
		ER.val[36] = R[i-1].val[23];
		ER.val[37] = R[i-1].val[24];
		ER.val[38] = R[i-1].val[25];
		ER.val[39] = R[i-1].val[26];
		ER.val[40] = R[i-1].val[27];
		ER.val[41] = R[i-1].val[28];
		
		ER.val[42] = R[i-1].val[27];
		ER.val[43] = R[i-1].val[28];
		ER.val[44] = R[i-1].val[29];
		ER.val[45] = R[i-1].val[30];
		ER.val[46] = R[i-1].val[31];
		ER.val[47] = R[i-1].val[0];
		
		cout<<"E(R"<<i-1<<")\t\t=";
		for(j = 0 ; j < 48 ; j++){
			if(j%6 ==0) cout<<" "<<ER.val[j];
			else cout<<ER.val[j];
		}
		cout<<endl;
		cout<<"K"<<i<<"\t\t=";
		for(j = 0 ; j < 48 ; j++){
			if(j%6 ==0) cout<<" "<<Key[i].val[j];
			else cout<<Key[i].val[j];
		}
		cout<<endl;
		// XOR K ke i dengan E(R) ke i-1
		for(j = 0 ; j < 48 ; j++){
			temp[j]= ER.val[j];
		}
		for(j = 0 ; j < 48 ; j++){
			ER.val[j] = XOR(temp[j],Key[i].val[j]);
		}
		cout<<"K"<<i<<" XOR E(R"<<i-1<<")\t=";
		for(j = 0 ; j < 48 ; j++){
			if(j%6 ==0) cout<<" "<<ER.val[j];
			else cout<<ER.val[j];
		}
		cout<<endl;
		//Subtitution
		int s1[4][16] =
	    {
	        14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,
	        0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,
	        4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,
	        15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13
	    };
	     int s2[4][16] =
	    {
	        15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10,
	        3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5,
	        0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15,
	        13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9
	    };
	    int s3[4][16] =
	    {
	        10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8,
	        13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1,
	        13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7,
	        1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12
	    };
	    int s4[4][16] =
	    {
	        7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15,
	        13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9,
	        10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4,
	        3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14
	    };	 
	    int s5[4][16] =
	    {
	        2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9,
	        14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6,
	        4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14,
	        11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3
	    };	 
	    int s6[4][16] =
	    {
	        12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11,
	        10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8,
	        9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6,
	        4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13
	    };	 
	    int s7[4][16] =
	    {
	        4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1,
	        13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6,
	        1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2,
	        6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12
	    };	 
	    int s8[4][16] =
	    {
	        13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7,
	        1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2,
	        7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8,
	        2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11
	    };
	    
	    j = 0;
	    k = 0;
	    int Sbox[8] = {0,0,0,0,0,0,0,0};
	    while(k < 8){
	    	int row = BIN2DEC(ER.val[j],ER.val[j+5]);
	    	int col = BIN4DEC(ER.val[j+1],ER.val[j+2],ER.val[j+3],ER.val[j+4]);
	    	//Text64 Sbox;
	    	if(k == 0)	Sbox[k] = s1[row][col];
	    	else if(k == 1)	Sbox[k] = s2[row][col];
	    	else if(k == 2)	Sbox[k] = s3[row][col];
	    	else if(k == 3)	Sbox[k] = s4[row][col];
	    	else if(k == 4)	Sbox[k] = s5[row][col];
	    	else if(k == 5)	Sbox[k] = s6[row][col];
	    	else if(k == 6)	Sbox[k] = s7[row][col];
	    	else if(k == 7)	Sbox[k] = s8[row][col];
	    	j = j + 6;
	    	k++;
	    }

	    Text32 f;
	    for(j = 0 ; j < 32 ; j++){
			f.val[j] = '0';
		}
	    k = 0;
	    for(j = 0 ; j < 8 ; j++){
	    	if(Sbox[j] == 0){
	    		f.val[k] = '0';	
	    		f.val[k+1] = '0';	
	    		f.val[k+2] = '0';	
	    		f.val[k+3] = '0';	
	    	}else if(Sbox[j] == 1){
	    		f.val[k] = '0';	
	    		f.val[k+1] = '0';	
	    		f.val[k+2] = '0';	
	    		f.val[k+3] = '1';
	    	}else if(Sbox[j] == 2){
	    		f.val[k] = '0';	
	    		f.val[k+1] = '0';	
	    		f.val[k+2] = '1';	
	    		f.val[k+3] = '0';
	    	}else if(Sbox[j] == 3){
	    		f.val[k] = '0';	
	    		f.val[k+1] = '0';	
	    		f.val[k+2] = '1';	
	    		f.val[k+3] = '1';
	    	}else if(Sbox[j] == 4){
	    		f.val[k] = '0';	
	    		f.val[k+1] = '1';	
	    		f.val[k+2] = '0';	
	    		f.val[k+3] = '0';
	    	}else if(Sbox[j] == 5){
	    		f.val[k] = '0';	
	    		f.val[k+1] = '1';	
	    		f.val[k+2] = '0';	
	    		f.val[k+3] = '1';
	    	}else if(Sbox[j] == 6){
	    		f.val[k] = '0';	
	    		f.val[k+1] = '1';	
	    		f.val[k+2] = '1';	
	    		f.val[k+3] = '0';
	    	}else if(Sbox[j] == 7){
	    		f.val[k] = '0';	
	    		f.val[k+1] = '1';	
	    		f.val[k+2] = '1';	
	    		f.val[k+3] = '1';
	    	}else if(Sbox[j] == 8){
	    		f.val[k] = '1';	
	    		f.val[k+1] = '0';	
	    		f.val[k+2] = '0';	
	    		f.val[k+3] = '0';
	    	}else if(Sbox[j] == 9){
	    		f.val[k] = '1';	
	    		f.val[k+1] = '0';	
	    		f.val[k+2] = '0';	
	    		f.val[k+3] = '1';
	    	}else if(Sbox[j] == 10){
	    		f.val[k] = '1';	
	    		f.val[k+1] = '0';	
	    		f.val[k+2] = '1';	
	    		f.val[k+3] = '0';
	    	}else if(Sbox[j] == 11){
	    		f.val[k] = '1';	
	    		f.val[k+1] = '0';	
	    		f.val[k+2] = '1';	
	    		f.val[k+3] = '1';
	    	}else if(Sbox[j] == 12){
	    		f.val[k] = '1';	
	    		f.val[k+1] = '1';	
	    		f.val[k+2] = '0';	
	    		f.val[k+3] = '0';
	    	}else if(Sbox[j] == 13){
	    		f.val[k] = '1';	
	    		f.val[k+1] = '1';	
	    		f.val[k+2] = '0';	
	    		f.val[k+3] = '1';
	    	}else if(Sbox[j] == 14){
	    		f.val[k] = '1';	
	    		f.val[k+1] = '1';	
	    		f.val[k+2] = '1';	
	    		f.val[k+3] = '0';
	    	}else if(Sbox[j] == 15){
	    		f.val[k] = '1';	
	    		f.val[k+1] = '1';	
	    		f.val[k+2] = '1';	
	    		f.val[k+3] = '1';
	    	}
	    	k = k + 4;
	    }
	    cout<<"Output Sbox\t=";
	    for(j = 0 ; j < 32 ; j++){
	    	temp[j] = f.val[j];
	    	if(j%4 ==0) cout<<" "<<f.val[j];
			else cout<<f.val[j];
	    }
	    cout<<endl;
	    //Permutatiton Table P
	     for(j = 0 ; j < 32 ; j++){
			f.val[j] = '1';
		}
		f.val[0] = temp[15];
		f.val[1] = temp[6];
		f.val[2] = temp[19];
		f.val[3] = temp[20];
				
		f.val[4] = temp[28];
		f.val[5] = temp[11];
		f.val[6] = temp[27];
		f.val[7] = temp[16];
		
		f.val[8] = temp[0];
		f.val[9] = temp[14];
		f.val[10] = temp[22];
		f.val[11] = temp[25];
		
		f.val[12] = temp[4];
		f.val[13] = temp[17];
		f.val[14] = temp[30];
		f.val[15] = temp[9];
		
		f.val[16] = temp[1];
		f.val[17] = temp[7];
		f.val[18] = temp[23];		
		f.val[19] = temp[13];
		
		f.val[20] = temp[31];
		f.val[21] = temp[26];
		f.val[22] = temp[2];		
		f.val[23] = temp[8];
		
		f.val[24] = temp[18];
		f.val[25] = temp[12];
		f.val[26] = temp[29];		
		f.val[27] = temp[5];
		
		f.val[28] = temp[21];
		f.val[29] = temp[10];
		f.val[30] = temp[3];
		f.val[31] = temp[24];
		cout<<"F(R"<<i-1<<",K"<<i<<")\t=";
	    for(j = 0 ; j < 32 ; j++){
	    	if(j%4 ==0) cout<<" "<<f.val[j];
			else cout<<f.val[j];
	    }
	    cout<<endl;
	    
	    //R ke i
	    for(j = 0 ; j <48 ; j++){
			R[i].val[j] = 'A';
		}
	   for(j = 0 ; j <48 ; j++){
			R[i].val[j] = XOR(L[i-1].val[j],f.val[j]);
		}
		cout<<"R"<<i<<" ="<<" L"<<i-1<<" XOR F(R"<<i-1<<",K"<<i<<") =";
	    for(j = 0 ; j < 32 ; j++){
	    	if(j%4 ==0) cout<<" "<<R[i].val[j];
			else cout<<R[i].val[j];
	    }
	    cout<<endl<<endl;
	    //system("pause");
	    //system("cls");
	    //next
	    //cout<<"Step "<<i+4<<". Mencari R"<<i<<endl;
	    if(i < 10) cout<<"L"<<i<<" = R"<<i-1<<"\t\t=";
	    else cout<<"L"<<i<<" = R"<<i-1<<"\t=";
	    
		for(j = 0 ; j < 32 ; j++){
			if(j%4 ==0) cout<<" "<<L[i].val[j];
			else cout<<L[i].val[j];
		}
		cout<<endl;
		cout<<"R"<<i<<"\t\t=";
	    for(j = 0 ; j < 32 ; j++){
	    	if(j%4 ==0) cout<<" "<<R[i].val[j];
			else cout<<R[i].val[j];
	    }
	    cout<<endl;
	}
	system("pause");
	system("cls");
//	cout<<"Step 21. Permutasi IP^-1 kepada L16R16"<<endl;
	char chiper_text[64];
	for(i = 0 ; i < 32 ; i++){
		temp[i] = R[16].val[i];
		temp[i+32] = L[16].val[i];
	}
	
	j = 40, k = 8;
	int l = 1;
	for(i = 0 ; i < 64 ; i++){
		if(i%8 == 0){
			j = 40-l;
			k = 8-l;
			l++;
		}
		if(i%2 == 1){
			chiper_text[i] = temp[j];
			j += 8;
		}else{
			chiper_text[i] = temp[k];
			k += 8;
		}
	}
	cout<<"Chiper text = ";
	for(i = 0 ; i < 64 ; i++){
		if(i%8 ==0) cout<<" "<<chiper_text[i];
		else cout<<chiper_text[i];
	}
	cout<<endl;
}
