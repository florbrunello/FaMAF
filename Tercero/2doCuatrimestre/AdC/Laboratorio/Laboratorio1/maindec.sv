// Maindec

module maindec (input logic [10:0] Op,
					 output logic Reg2Loc, ALUSrc, MemtoReg, RegWrite, MemRead, MemWrite, Branch, 
					 output logic [1:0] ALUOp); 
	 
	always_comb 
		begin 
			casez(Op)
				
				11'b111_1100_0010: 
					begin
						Reg2Loc <= 1'b0;
						ALUSrc <= 1'b1;
						MemtoReg <= 1'b1;
						RegWrite <= 1'b1;
						MemRead <= 1'b1;
						MemWrite <= 1'b0;
						Branch <= 1'b0;
						ALUOp <= 2'b00;
					end
			
				11'b111_1100_0000: 
					begin
						Reg2Loc <= 1'b1;
						ALUSrc <= 1'b1;
						MemtoReg <= 1'b0;
						RegWrite <= 1'b0;
						MemRead <= 1'b0;
						MemWrite <= 1'b1;
						Branch <= 1'b0;
						ALUOp <= 2'b00;
					end
					
				11'b101_1010_0???: 
					begin
						Reg2Loc <= 1'b1;
						ALUSrc <= 1'b0;
						MemtoReg <= 1'b0;
						RegWrite <= 1'b0;
						MemRead <= 1'b0;
						MemWrite <= 1'b0;
						Branch <= 1'b1;
						ALUOp <= 2'b01;
					end

				11'b100_0101_1000: 
					begin
						Reg2Loc <= 1'b0;
						ALUSrc <= 1'b0;
						MemtoReg <= 1'b0;
						RegWrite <= 1'b1;
						MemRead <= 1'b0;
						MemWrite <= 1'b0;
						Branch <= 1'b0;
						ALUOp <= 2'b10;
					end
					
				11'b110_0101_1000: 
					begin
						Reg2Loc <= 1'b0;
						ALUSrc <= 1'b0;
						MemtoReg <= 1'b0;
						RegWrite <= 1'b1;
						MemRead <= 1'b0;
						MemWrite <= 1'b0;
						Branch <= 1'b0;
						ALUOp <= 2'b10;
					end
					
				11'b100_0101_0000: 
					begin	
						Reg2Loc <= 1'b0;
						ALUSrc <= 1'b0;
						MemtoReg <= 1'b0;
						RegWrite <= 1'b1;
						MemRead <= 1'b0;
						MemWrite <= 1'b0;
						Branch <= 1'b0;
						ALUOp <= 2'b10;
					end
					
				11'b101_0101_0000: 
					begin
						Reg2Loc <= 1'b0;
						ALUSrc <= 1'b0;
						MemtoReg <= 1'b0;
						RegWrite <= 1'b1;
						MemRead <= 1'b0;
						MemWrite <= 1'b0;
						Branch <= 1'b0;
						ALUOp <= 2'b10;
					end

				default:
					begin
						Reg2Loc <= 1'b0;
						ALUSrc <= 1'b0;
						MemtoReg <= 1'b0;
						RegWrite <= 1'b0;
						MemRead <= 1'b0;
						MemWrite <= 1'b0;
						Branch <= 1'b0;
						ALUOp <= 2'b00;
					end
			
			endcase
		end 
		
endmodule