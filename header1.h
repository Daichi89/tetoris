#pragma once

#ifndef A_H_
#define A_H_
#define FIELD_WIDTH 12
#define FIELD_HEIGHT 22
#define MINO_WIDTH 4
#define MINO_HEIGHT 4

enum {
	MINO_TYPE_I,
	MINO_TYPE_O,
	MINO_TYPE_S,
	MINO_TYPE_Z,
	MINO_TYPE_J,
	MINO_TYPE_L,
	MINO_TYPE_T,
	MINO_TYPE_MAX
};

enum {
	MINO_ANGLE_0,
	MINO_ANGLE_90,
	MINO_ANGLE_180,
	MINO_ANGLE_270,
	MINO_ANGLE_MAX,
};

class Brock {
	public:
	static char field[FIELD_HEIGHT][FIELD_WIDTH];
	static char displayBuffer[FIELD_HEIGHT][FIELD_WIDTH];
	char minoShapes[MINO_TYPE_MAX][MINO_ANGLE_MAX][MINO_WIDTH][MINO_HEIGHT] = {
		//MINO_TYPE_I,
		{
			//MINO_ANGLE_0
			{
				0, 1, 0, 0,
				0, 1, 0, 0,
				0, 1, 0, 0,
				0, 1, 0, 0,
			},
			//MINO_ANGLE_90
			{
				0, 0, 0, 0,
				0, 0, 0, 0,
				1, 1, 1, 1,
				0, 0, 0, 0,
			},
			//MINO_ANGLE_18
			{
				0, 0, 1, 0,
				0, 0, 1, 0,
				0, 0, 1, 0,
				0, 0, 1, 0,
			},
			//MINO_ANGLE_270
			{
				0, 0, 0, 0,
				1, 1, 1, 1,
				0, 0, 0, 0,
				0, 0, 0, 0,
			},
		},
		//MINO_TYPE_O,
		{
			//MINO_ANGLE_0,
			{
				0, 0, 0, 0,
				0, 1, 1, 0,
				0, 1, 1, 0,
				0, 0, 0, 0,
			},

			//MINO_ANGLE_90,
			   {
				   0, 0, 0, 0,
				   0, 1, 1, 0,
				   0, 1, 1, 0,
				   0, 0, 0, 0,
			   },
			   //MINO_ANGLE_180,
				   {
					   0, 0, 0, 0,
					   0, 1, 1, 0,
					   0, 1, 1, 0,
					   0, 0, 0, 0,
				   },
				   //MINO_ANGLE_270
					   {
						   0, 0, 0, 0,
						   0, 1, 1, 0,
						   0, 1, 1, 0,
						   0, 0, 0, 0,
					   },
				   },
				   //MINO_TYPE_S,
				   {
					   //MINO_ANGLE_0,
						   {
							   0, 0, 0, 0,
							   0, 1, 1, 0,
							   1, 1, 0, 0,
							   0, 0, 0, 0,
						   },
						   //MINO_ANGLE_90,
							   {
								   0, 1, 0, 0,
								   0, 1, 1, 0,
								   0, 0, 1, 0,
								   0, 0, 0, 0,
							   },
							   //MINO_ANGLE_180,
								   {
									   0, 0, 0, 0,
									   0, 1, 1, 0,
									   1, 1, 0, 0,
									   0, 0, 0, 0,
								   },
								   //MINO_ANGLE_270
									   {
										   0, 0, 0, 0,
										   1, 0, 0, 0,
										   1, 1, 0, 0,
										   0, 1, 0, 0,
									   },
								   },
								   //MINO_TYPE_Z,
								   {
									   {
										   0 ,0, 0, 0,
										   1, 1, 0, 0,
										   0, 1, 1, 0,
										   0, 0, 0, 0,
									   },
									   //MINO_ANGLE_90,
										   {
											   0 ,0, 0, 0,
											   0, 0, 1, 0,
											   0, 1, 1, 0,
											   0, 1, 0, 0,
										   },
										   //MINO_ANGLE_180,
											   {
												   0 ,0, 0, 0,
												   0, 0, 0, 0,
												   0, 1, 1, 0,
												   0, 0, 1, 1,
											   },
											   //MINO_ANGLE_270
												   {
													   0 ,0, 0, 0,
													   0, 0, 1, 0,
													   0, 1, 1, 0,
													   0, 1, 0, 0,
												   },
											   },
											   //MINO_TYPE_J,
											   {
												   {
													   0 ,0, 1, 0,
													   0, 0, 1, 0,
													   0, 1, 1, 0,
													   0, 0, 0, 0,
												   },
												   //MINO_ANGLE_90,
													   {
														   0 ,0, 0, 0,
														   1, 1, 1, 0,
														   0, 0, 1, 0,
														   0, 0, 0, 0,
													   },
													   //MINO_ANGLE_180,
														   {
															   0 ,0, 0, 0,
															   0, 1, 1, 0,
															   0, 1, 0, 0,
															   0, 1, 0, 0,
														   },
														   //MINO_ANGLE_270
															   {
																   0 ,0, 0, 0,
																   0, 1, 0, 0,
																   0, 1, 1, 1,
																   0, 0, 0, 0,
															   },
														   },
														   //MINO_TYPE_L,
														   {
															   {
																   0 ,1, 0, 0,
																   0, 1, 0, 0,
																   0, 1, 1, 0,
																   0, 0, 0, 0,
															   },

															   //MINO_ANGLE_90,
																   {
																	   0 ,0, 0, 0,
																	   0, 0, 1, 0,
																	   1, 1, 1, 0,
																	   0, 0, 0, 0,
																   },
																   //MINO_ANGLE_180,
																	   {
																		   0 ,0, 0, 0,
																		   0, 1, 1, 0,
																		   0, 0, 1, 0,
																		   0, 0, 1, 0,
																	   },
																	   //MINO_ANGLE_270
																		   {
																			   0 ,0, 0, 0,
																			   0, 1, 1, 1,
																			   0, 1, 0, 0,
																			   0, 0, 0, 0,
																		   },
																	   },
																	   //MINO_TYPE_T,
																	   {
																		   {
																			   0 ,0, 0, 0,
																			   1, 1, 1, 0,
																			   0, 1, 0, 0,
																			   0, 0, 0, 0,
																		   },

																		   //MINO_ANGLE_90,
																			   {
																				   0 ,0, 0, 0,
																				   0, 1, 0, 0,
																				   0, 1, 1, 0,
																				   0, 1, 0, 0,
																			   },
																			   //MINO_ANGLE_180,
																				   {
																					   0 ,0, 0, 0,
																					   0, 0, 1, 0,
																					   0, 1, 1, 1,
																					   0, 0, 0, 0,
																				   },
																				   //MINO_ANGLE_270
																					   {
																						   0 ,0, 0, 0,
																						   0, 0, 1, 0,
																						   0, 1, 1, 0,
																						   0, 0, 1, 0,
																					   },
																				   },
	};
};

class Wall{
public:
	void setWall();
	Brock bro;
};

class Mino {
private:
	static int minoType;
	static int minoAngle;
	static int minoX;
	static int minoY;
public:
	void resetMino();
	void changeAngle();
	bool isHit(int _minoX, int _minoY, int minoTypem, int _minoAngle);
	void display();
	void crash();
	void mbreak();
	Brock bro;
	Mino();
};

#endif
