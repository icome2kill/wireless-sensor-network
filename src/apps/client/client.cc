/*
 *  created on : Mar 5, 2014
 *      author : Mr.Quan LE
 *      email  : lequana2@gmail.com
 *
 *  functioning: refer to client.h
 */

#include <fstream>
#include "client.h"
#include "radio.h"
#include "statistic.h"
#include "data_m.h"
#include "lzw.h"

// define number of packet each sensor need to send
//#define MAX 60
//#define MAX 1

#ifndef DEBUG
#define DEBUG 0
#endif

using namespace std;

namespace wsn_energy {
static const unsigned short SOIL_MOISTURE[1500] = { 74, 62, 79, 74, 71, 74, 61,
        66, 71, 76, 75, 73, 78, 78, 72, 69, 76, 78, 66, 79, 70, 67, 66, 79, 63,
        79, 79, 75, 70, 74, 69, 69, 63, 74, 69, 77, 70, 75, 64, 72, 62, 77, 75,
        67, 71, 72, 61, 71, 67, 64, 71, 69, 70, 79, 78, 70, 79, 69, 78, 61, 74,
        65, 60, 62, 70, 74, 79, 61, 60, 65, 65, 73, 69, 66, 64, 62, 63, 72, 78,
        64, 68, 68, 66, 69, 75, 64, 79, 70, 73, 78, 78, 76, 75, 76, 75, 68, 60,
        62, 76, 67, 79, 75, 71, 65, 69, 62, 70, 61, 66, 71, 61, 77, 77, 62, 69,
        71, 75, 64, 73, 64, 75, 70, 70, 67, 65, 73, 71, 77, 67, 76, 68, 79, 77,
        69, 62, 77, 68, 66, 79, 70, 70, 66, 64, 63, 66, 62, 73, 70, 69, 69, 66,
        64, 70, 73, 70, 73, 68, 75, 60, 66, 67, 64, 71, 79, 64, 64, 73, 79, 63,
        74, 71, 77, 75, 72, 71, 64, 60, 71, 73, 74, 64, 73, 79, 67, 63, 64, 62,
        64, 60, 77, 69, 72, 79, 65, 79, 67, 60, 70, 65, 66, 75, 73, 67, 72, 74,
        63, 65, 71, 66, 72, 64, 71, 65, 62, 69, 64, 61, 68, 70, 61, 69, 70, 75,
        62, 77, 68, 68, 76, 77, 62, 64, 71, 68, 74, 62, 64, 70, 77, 60, 63, 64,
        65, 64, 71, 66, 72, 79, 65, 71, 64, 69, 72, 72, 61, 63, 75, 68, 68, 66,
        79, 66, 60, 61, 67, 69, 64, 74, 74, 61, 74, 72, 66, 79, 61, 62, 60, 60,
        62, 71, 78, 67, 66, 70, 62, 74, 68, 61, 67, 74, 79, 69, 66, 62, 73, 74,
        76, 67, 77, 60, 77, 63, 61, 77, 60, 66, 66, 72, 66, 69, 73, 71, 60, 74,
        64, 75, 76, 77, 77, 77, 71, 77, 65, 60, 72, 60, 60, 72, 68, 79, 69, 66,
        71, 75, 62, 66, 60, 68, 64, 63, 64, 77, 62, 76, 71, 77, 62, 70, 61, 77,
        71, 65, 71, 71, 63, 73, 63, 75, 66, 76, 67, 63, 75, 67, 75, 66, 76, 64,
        66, 65, 77, 70, 65, 70, 78, 72, 66, 70, 64, 76, 73, 69, 61, 60, 70, 63,
        77, 75, 72, 75, 70, 65, 72, 65, 76, 71, 78, 61, 62, 75, 76, 71, 68, 72,
        64, 78, 63, 64, 65, 69, 74, 72, 74, 70, 67, 60, 71, 74, 67, 79, 78, 69,
        69, 67, 64, 73, 75, 76, 73, 70, 68, 67, 64, 77, 61, 66, 62, 77, 76, 65,
        73, 60, 73, 72, 67, 62, 71, 79, 61, 71, 72, 74, 66, 63, 79, 63, 72, 75,
        68, 77, 78, 63, 69, 71, 78, 60, 60, 60, 65, 74, 79, 63, 63, 66, 74, 61,
        75, 69, 71, 68, 78, 70, 60, 77, 78, 60, 76, 70, 69, 76, 73, 77, 60, 78,
        60, 69, 60, 60, 79, 76, 76, 72, 66, 72, 64, 62, 68, 70, 72, 69, 61, 72,
        60, 63, 74, 75, 63, 72, 70, 70, 71, 68, 72, 73, 63, 77, 74, 64, 70, 78,
        77, 75, 60, 72, 63, 72, 64, 76, 74, 68, 71, 69, 68, 67, 61, 73, 64, 76,
        73, 76, 72, 78, 65, 66, 76, 77, 60, 60, 73, 62, 61, 75, 62, 66, 62, 68,
        78, 69, 73, 77, 73, 73, 71, 61, 74, 69, 66, 78, 70, 75, 71, 63, 62, 72,
        63, 67, 75, 64, 78, 65, 78, 66, 75, 72, 79, 60, 66, 64, 77, 70, 76, 61,
        64, 67, 64, 69, 79, 71, 60, 76, 67, 67, 72, 78, 78, 76, 64, 72, 73, 79,
        63, 62, 67, 61, 76, 75, 61, 77, 71, 64, 70, 78, 68, 74, 69, 63, 70, 79,
        79, 79, 65, 74, 67, 67, 62, 70, 78, 78, 60, 67, 64, 60, 76, 69, 64, 69,
        63, 71, 72, 64, 63, 62, 79, 62, 68, 65, 71, 74, 64, 62, 64, 75, 70, 64,
        79, 64, 78, 76, 72, 72, 61, 74, 77, 65, 77, 71, 77, 75, 63, 73, 62, 72,
        70, 71, 61, 70, 71, 69, 73, 68, 67, 74, 60, 63, 67, 76, 77, 70, 71, 61,
        78, 78, 64, 70, 73, 66, 71, 68, 63, 72, 71, 78, 72, 68, 79, 76, 76, 72,
        70, 71, 75, 77, 79, 78, 68, 65, 68, 68, 76, 60, 70, 78, 72, 79, 79, 78,
        68, 67, 61, 65, 67, 70, 70, 61, 60, 60, 74, 72, 67, 63, 74, 61, 60, 72,
        71, 65, 75, 64, 67, 68, 74, 66, 76, 76, 71, 74, 76, 71, 61, 76, 77, 76,
        74, 76, 68, 76, 67, 69, 72, 66, 68, 74, 74, 70, 74, 74, 68, 63, 75, 76,
        63, 65, 65, 79, 60, 64, 68, 68, 79, 67, 78, 70, 69, 73, 62, 66, 62, 70,
        77, 65, 75, 64, 72, 61, 61, 79, 73, 63, 72, 79, 63, 71, 64, 65, 76, 73,
        72, 64, 72, 77, 71, 60, 62, 65, 71, 70, 69, 70, 61, 68, 74, 63, 72, 66,
        77, 71, 71, 77, 76, 65, 74, 73, 64, 69, 70, 71, 69, 64, 79, 72, 68, 71,
        60, 72, 79, 60, 60, 60, 70, 79, 77, 77, 73, 61, 60, 60, 78, 69, 60, 71,
        78, 68, 66, 60, 74, 61, 62, 78, 63, 69, 61, 63, 70, 60, 67, 75, 71, 68,
        71, 76, 70, 76, 71, 64, 75, 65, 66, 60, 65, 77, 73, 76, 69, 64, 68, 64,
        65, 76, 63, 62, 69, 61, 64, 74, 62, 67, 65, 76, 78, 74, 70, 69, 60, 63,
        71, 77, 62, 76, 60, 72, 66, 63, 76, 78, 74, 78, 79, 78, 74, 65, 79, 69,
        78, 62, 60, 73, 67, 67, 66, 65, 79, 70, 71, 71, 67, 62, 63, 75, 60, 71,
        71, 61, 62, 77, 71, 77, 74, 73, 61, 65, 74, 69, 75, 77, 71, 75, 70, 79,
        63, 62, 68, 63, 61, 78, 75, 65, 67, 66, 66, 64, 63, 78, 70, 65, 60, 64,
        60, 78, 69, 73, 67, 65, 74, 75, 77, 78, 72, 64, 70, 63, 72, 61, 72, 61,
        75, 61, 71, 66, 78, 65, 68, 75, 60, 74, 73, 65, 74, 70, 65, 75, 77, 64,
        60, 63, 61, 71, 73, 75, 66, 78, 60, 71, 78, 60, 65, 73, 66, 67, 68, 78,
        78, 71, 67, 60, 65, 65, 76, 66, 63, 62, 72, 62, 71, 61, 64, 64, 75, 66,
        62, 61, 61, 62, 78, 73, 67, 67, 76, 64, 63, 63, 62, 63, 75, 79, 65, 67,
        67, 62, 78, 76, 63, 74, 76, 62, 76, 75, 71, 75, 75, 74, 61, 74, 75, 72,
        64, 77, 60, 64, 71, 62, 69, 70, 65, 64, 70, 61, 77, 74, 67, 68, 74, 73,
        68, 77, 68, 77, 72, 70, 70, 72, 66, 70, 74, 67, 71, 68, 60, 76, 69, 69,
        61, 75, 79, 69, 68, 60, 63, 75, 70, 77, 67, 74, 61, 73, 65, 76, 79, 72,
        76, 73, 67, 77, 61, 61, 68, 70, 77, 70, 60, 75, 64, 77, 71, 74, 70, 63,
        66, 69, 65, 63, 66, 78, 70, 60, 76, 61, 78, 61, 74, 64, 61, 61, 63, 71,
        76, 66, 70, 77, 79, 77, 70, 63, 70, 72, 63, 69, 71, 71, 68, 61, 64, 76,
        64, 64, 75, 78, 79, 74, 60, 69, 69, 76, 61, 66, 63, 67, 67, 73, 67, 63,
        60, 71, 66, 73, 73, 65, 75, 60, 72, 77, 65, 61, 75, 71, 70, 66, 63, 71,
        73, 73, 73, 78, 62, 76, 62, 70, 69, 72, 79, 72, 61, 78, 60, 79, 76, 79,
        73, 71, 78, 76, 63, 79, 66, 76, 61, 63, 69, 61, 78, 61, 66, 75, 72, 73,
        63, 66, 63, 68, 76, 73, 64, 68, 63, 74, 76, 66, 78, 77, 70, 75, 60, 74,
        63, 77, 70, 73, 60, 76, 76, 64, 78, 68, 75, 66, 69, 68, 61, 71, 61, 77,
        69, 77, 62, 62, 78, 69, 72, 62, 70, 73, 77, 71, 73, 60, 74, 71, 73, 75,
        77, 63, 67, 71, 62, 79, 72, 74, 78, 65, 64, 65, 64, 68, 68, 70, 60, 69,
        73, 60, 75, 64, 76, 60, 73, 62, 71, 70, 66, 75, 68, 62, 79, 63, 71, 69,
        60, 75, 63, 76, 66, 68, 60, 73, 73, 79, 65, 75, 75, 62, 76, 66, 78, 66,
        74, 78, 65, 61, 66, 74, 66, 76, 67, 69, 62, 66, 61, 71, 74, 68, 64, 73,
        78, 66, 70, 66, 72, 66, 64, 71, 78, 60, 62, 79, 71, 79, 61, 69, 65, 75,
        75, 73, 72, 60, 61, 70, 75, 64, 79, 70, 60, 66, 60, 60, 64, 65, 78, 63,
        62, 60, 63, 62, 68, 70, 74, 75, 78, 70, 74, 64, 63, 73, 78, 67, 66, 60,
        63, 69, 70, 72, 75, 77, 60, 67, 67, 61, 68, 62, 71, 72, 63, 63, 78 };
static const unsigned short SOIL_PH[1500] = { 5117, 5071, 5002, 5197, 5160,
        5107, 5172, 5051, 5030, 5013, 5083, 5180, 5148, 5147, 5162, 5093, 5189,
        5186, 5169, 5090, 5068, 5100, 5165, 5107, 5113, 5131, 5172, 5051, 5199,
        5194, 5182, 5041, 5198, 5105, 5045, 5025, 5131, 5004, 5023, 5008, 5000,
        5083, 5166, 5048, 5113, 5037, 5184, 5050, 5164, 5114, 5055, 5069, 5067,
        5059, 5129, 5139, 5126, 5007, 5025, 5050, 5095, 5144, 5144, 5102, 5145,
        5015, 5034, 5160, 5017, 5146, 5014, 5156, 5128, 5010, 5133, 5178, 5086,
        5150, 5055, 5099, 5147, 5006, 5088, 5034, 5155, 5110, 5144, 5000, 5121,
        5001, 5110, 5002, 5030, 5139, 5130, 5025, 5154, 5058, 5099, 5181, 5118,
        5018, 5046, 5079, 5092, 5160, 5184, 5012, 5024, 5161, 5167, 5036, 5072,
        5135, 5101, 5152, 5185, 5134, 5177, 5194, 5132, 5036, 5074, 5126, 5076,
        5044, 5003, 5038, 5057, 5030, 5106, 5149, 5096, 5093, 5125, 5074, 5101,
        5124, 5052, 5079, 5027, 5175, 5002, 5025, 5188, 5107, 5118, 5196, 5102,
        5070, 5080, 5083, 5044, 5186, 5176, 5167, 5164, 5085, 5082, 5090, 5052,
        5072, 5158, 5071, 5105, 5103, 5071, 5002, 5127, 5079, 5095, 5093, 5180,
        5092, 5123, 5044, 5049, 5067, 5125, 5108, 5108, 5168, 5059, 5031, 5124,
        5042, 5010, 5051, 5186, 5106, 5053, 5175, 5059, 5085, 5119, 5163, 5162,
        5005, 5118, 5025, 5036, 5155, 5133, 5159, 5073, 5016, 5152, 5132, 5160,
        5196, 5074, 5189, 5076, 5030, 5168, 5199, 5012, 5093, 5084, 5177, 5138,
        5096, 5149, 5020, 5075, 5106, 5173, 5058, 5176, 5103, 5057, 5148, 5168,
        5087, 5086, 5060, 5136, 5198, 5067, 5163, 5036, 5088, 5094, 5082, 5183,
        5118, 5104, 5136, 5077, 5005, 5151, 5028, 5109, 5106, 5098, 5042, 5085,
        5172, 5052, 5044, 5119, 5048, 5167, 5061, 5083, 5147, 5165, 5097, 5089,
        5180, 5111, 5193, 5094, 5175, 5151, 5065, 5155, 5086, 5124, 5131, 5137,
        5149, 5101, 5095, 5145, 5166, 5113, 5064, 5183, 5157, 5076, 5015, 5190,
        5080, 5158, 5116, 5015, 5124, 5193, 5106, 5046, 5123, 5106, 5098, 5032,
        5125, 5151, 5198, 5088, 5191, 5023, 5050, 5102, 5047, 5090, 5144, 5023,
        5189, 5089, 5121, 5048, 5010, 5076, 5134, 5164, 5036, 5044, 5161, 5034,
        5118, 5115, 5073, 5021, 5036, 5104, 5004, 5130, 5104, 5197, 5122, 5070,
        5133, 5133, 5033, 5022, 5106, 5141, 5013, 5074, 5023, 5037, 5062, 5115,
        5122, 5062, 5041, 5150, 5046, 5022, 5161, 5026, 5188, 5136, 5083, 5086,
        5196, 5078, 5136, 5045, 5063, 5183, 5142, 5073, 5158, 5062, 5113, 5031,
        5163, 5104, 5193, 5154, 5180, 5124, 5034, 5158, 5060, 5046, 5066, 5199,
        5035, 5115, 5050, 5099, 5107, 5199, 5178, 5083, 5052, 5056, 5112, 5084,
        5170, 5188, 5030, 5198, 5008, 5160, 5083, 5109, 5064, 5077, 5195, 5131,
        5154, 5050, 5068, 5034, 5145, 5052, 5103, 5138, 5153, 5047, 5081, 5169,
        5186, 5075, 5067, 5197, 5097, 5137, 5043, 5156, 5060, 5016, 5121, 5165,
        5023, 5011, 5189, 5024, 5189, 5146, 5099, 5123, 5085, 5124, 5073, 5190,
        5165, 5063, 5185, 5127, 5162, 5184, 5023, 5032, 5141, 5007, 5138, 5012,
        5179, 5130, 5021, 5015, 5155, 5172, 5000, 5019, 5185, 5054, 5115, 5125,
        5037, 5092, 5154, 5018, 5052, 5008, 5047, 5062, 5164, 5047, 5064, 5086,
        5179, 5133, 5115, 5149, 5003, 5164, 5038, 5183, 5159, 5035, 5072, 5161,
        5030, 5092, 5167, 5035, 5152, 5044, 5008, 5133, 5161, 5077, 5195, 5169,
        5149, 5145, 5181, 5075, 5030, 5026, 5001, 5163, 5089, 5151, 5035, 5130,
        5165, 5137, 5145, 5145, 5037, 5080, 5168, 5025, 5167, 5032, 5168, 5029,
        5082, 5029, 5173, 5057, 5197, 5193, 5111, 5108, 5034, 5061, 5163, 5142,
        5163, 5042, 5009, 5007, 5073, 5194, 5014, 5090, 5042, 5177, 5000, 5109,
        5081, 5057, 5040, 5130, 5015, 5170, 5117, 5177, 5112, 5140, 5116, 5018,
        5087, 5131, 5139, 5019, 5180, 5055, 5123, 5079, 5105, 5141, 5122, 5098,
        5007, 5196, 5035, 5002, 5037, 5095, 5071, 5053, 5068, 5121, 5078, 5117,
        5176, 5097, 5029, 5077, 5160, 5066, 5154, 5117, 5185, 5161, 5130, 5153,
        5117, 5102, 5174, 5137, 5061, 5066, 5061, 5149, 5162, 5124, 5197, 5048,
        5176, 5189, 5129, 5127, 5116, 5007, 5175, 5163, 5058, 5070, 5155, 5129,
        5036, 5108, 5108, 5129, 5191, 5044, 5191, 5070, 5001, 5066, 5160, 5184,
        5033, 5134, 5104, 5027, 5144, 5153, 5052, 5009, 5126, 5041, 5057, 5044,
        5087, 5062, 5182, 5073, 5066, 5061, 5070, 5006, 5105, 5109, 5146, 5001,
        5181, 5012, 5178, 5197, 5125, 5070, 5192, 5074, 5144, 5127, 5102, 5073,
        5159, 5044, 5168, 5076, 5198, 5114, 5016, 5039, 5185, 5097, 5176, 5074,
        5131, 5049, 5168, 5027, 5130, 5193, 5046, 5104, 5040, 5126, 5157, 5065,
        5065, 5154, 5011, 5063, 5118, 5150, 5179, 5094, 5162, 5145, 5140, 5015,
        5151, 5099, 5023, 5019, 5184, 5160, 5074, 5163, 5009, 5062, 5082, 5096,
        5040, 5130, 5109, 5199, 5009, 5001, 5066, 5147, 5005, 5082, 5175, 5170,
        5046, 5064, 5019, 5145, 5129, 5121, 5152, 5074, 5104, 5090, 5155, 5184,
        5174, 5186, 5194, 5173, 5086, 5116, 5175, 5199, 5076, 5040, 5191, 5012,
        5195, 5184, 5047, 5131, 5090, 5110, 5192, 5030, 5199, 5148, 5192, 5147,
        5102, 5083, 5181, 5178, 5128, 5180, 5180, 5038, 5033, 5167, 5048, 5115,
        5130, 5019, 5148, 5087, 5133, 5072, 5132, 5073, 5042, 5101, 5059, 5174,
        5025, 5164, 5171, 5068, 5053, 5000, 5064, 5054, 5079, 5088, 5117, 5101,
        5050, 5007, 5181, 5036, 5186, 5162, 5096, 5139, 5145, 5033, 5029, 5126,
        5089, 5124, 5048, 5133, 5092, 5133, 5072, 5050, 5085, 5105, 5195, 5178,
        5180, 5024, 5169, 5124, 5175, 5179, 5194, 5143, 5163, 5065, 5022, 5021,
        5050, 5132, 5006, 5128, 5172, 5167, 5142, 5176, 5055, 5048, 5112, 5011,
        5080, 5087, 5006, 5086, 5018, 5030, 5173, 5170, 5198, 5079, 5154, 5112,
        5074, 5123, 5028, 5151, 5071, 5064, 5023, 5068, 5030, 5009, 5020, 5193,
        5042, 5160, 5177, 5122, 5036, 5041, 5112, 5071, 5124, 5044, 5128, 5005,
        5091, 5198, 5076, 5009, 5130, 5184, 5170, 5017, 5085, 5038, 5008, 5039,
        5104, 5170, 5113, 5097, 5077, 5064, 5068, 5028, 5111, 5167, 5099, 5091,
        5111, 5167, 5037, 5035, 5032, 5179, 5027, 5088, 5060, 5141, 5144, 5181,
        5082, 5115, 5004, 5193, 5075, 5027, 5028, 5068, 5166, 5109, 5052, 5129,
        5063, 5188, 5115, 5083, 5042, 5183, 5142, 5011, 5055, 5050, 5066, 5094,
        5000, 5135, 5126, 5141, 5190, 5019, 5146, 5018, 5147, 5160, 5069, 5140,
        5019, 5189, 5101, 5029, 5056, 5166, 5025, 5159, 5198, 5108, 5048, 5048,
        5106, 5146, 5165, 5004, 5041, 5107, 5070, 5198, 5180, 5014, 5161, 5055,
        5032, 5097, 5094, 5057, 5052, 5131, 5149, 5187, 5038, 5079, 5024, 5146,
        5127, 5074, 5115, 5084, 5106, 5180, 5132, 5133, 5192, 5046, 5072, 5183,
        5156, 5195, 5168, 5181, 5025, 5081, 5164, 5049, 5069, 5011, 5199, 5129,
        5012, 5147, 5180, 5077, 5132, 5150, 5040, 5067, 5188, 5157, 5193, 5025,
        5088, 5162, 5088, 5024, 5109, 5016, 5015, 5025, 5081, 5147, 5178, 5102,
        5139, 5162, 5174, 5043, 5100, 5169, 5024, 5032, 5025, 5168, 5150, 5165,
        5042, 5188, 5114, 5120, 5031, 5179, 5196, 5183, 5069, 5090, 5122, 5085,
        5183, 5192, 5195, 5086, 5019, 5094, 5080, 5142, 5189, 5138, 5186, 5020,
        5046, 5077, 5050, 5055, 5054, 5140, 5064, 5187, 5073, 5091, 5060, 5006,
        5116, 5037, 5032, 5011, 5094, 5046, 5076, 5113, 5194, 5023, 5181, 5023,
        5046, 5045, 5073, 5063, 5113, 5127, 5157, 5071, 5062, 5158, 5096, 5142,
        5164, 5009, 5093, 5111, 5036, 5122, 5163, 5168, 5027, 5069, 5118, 5085,
        5096, 5160, 5098, 5075, 5147, 5021, 5155, 5090, 5011, 5157, 5029, 5143,
        5044, 5026, 5016, 5058, 5181, 5098, 5022, 5059, 5051, 5053, 5148, 5013,
        5086, 5001, 5172, 5103, 5195, 5056, 5008, 5171, 5068, 5111, 5064, 5183,
        5191, 5025, 5136, 5012, 5018, 5128, 5072, 5057, 5188, 5070, 5196, 5085,
        5173, 5175, 5000, 5195, 5150, 5041, 5017, 5152, 5181, 5021, 5023, 5094,
        5144, 5133, 5094, 5139, 5016, 5069, 5000, 5147, 5006, 5053, 5125, 5125,
        5045, 5054, 5170, 5135, 5023, 5099, 5164, 5025, 5174, 5061, 5076, 5187,
        5022, 5073, 5153, 5068, 5184, 5188, 5029, 5149, 5185, 5018, 5159, 5077,
        5031, 5183, 5142, 5098, 5153, 5186, 5131, 5116, 5158, 5005, 5025, 5046,
        5124, 5020, 5183, 5065, 5123, 5128, 5116, 5017, 5045, 5044, 5168, 5162,
        5134, 5039, 5155, 5108, 5030, 5149, 5138, 5035, 5006, 5029, 5062, 5004,
        5162, 5160, 5120, 5154, 5144, 5147, 5088, 5037, 5033, 5155, 5151, 5123,
        5133, 5006, 5088, 5172, 5047, 5129, 5157, 5144, 5182, 5129, 5078, 5168,
        5038, 5192, 5089, 5067, 5131, 5133, 5094, 5082, 5124, 5155, 5054, 5020,
        5157, 5012, 5058, 5039, 5099, 5130, 5050, 5132, 5123, 5129, 5009, 5108,
        5128, 5135, 5030, 5023, 5187, 5086, 5043, 5060, 5191, 5031, 5012, 5035,
        5119, 5059, 5032, 5193, 5024, 5191, 5199, 5105, 5163, 5096, 5097, 5081,
        5027, 5190, 5048, 5129, 5135, 5127, 5130, 5057, 5176, 5086, 5049, 5158,
        5125, 5083, 5035, 5125, 5035, 5084, 5162, 5089, 5169, 5082, 5082, 5081,
        5012, 5122, 5077, 5101, 5103, 5096, 5107, 5003, 5107, 5042, 5080, 5136,
        5196, 5173, 5166, 5105, 5141, 5009, 5085, 5141, 5107, 5084, 5043, 5086,
        5163, 5146, 5074, 5075, 5018, 5142, 5056, 5111, 5010, 5157, 5010, 5034,
        5029, 5136, 5051, 5006, 5128, 5078, 5187, 5057, 5011, 5176, 5121, 5160,
        5024, 5167, 5048, 5066, 5163, 5172, 5138, 5050, 5025, 5030, 5015, 5128,
        5192, 5165, 5074, 5173, 5161, 5113, 5139, 5149, 5031, 5036, 5034, 5196,
        5188, 5171, 5127, 5176, 5172, 5107, 5050, 5006, 5097, 5048, 5063, 5049,
        5144, 5119, 5086, 5163, 5106, 5184, 5081, 5058, 5127, 5042, 5176, 5043,
        5150, 5146, 5081, 5006, 5088, 5198, 5178, 5166, 5156, 5146, 5032, 5009,
        5057, 5005, 5170, 5182, 5148, 5066, 5188, 5122, 5029, 5008, 5184, 5016,
        5165, 5167, 5057, 5022, 5106, 5060, 5187, 5135, 5056, 5155, 5049, 5165,
        5093, 5120, 5178, 5004, 5016, 5182, 5027 };
static const unsigned short MOISUTRE[500] = { 3762, 3733, 3716, 3866, 3871,
        3727, 3845, 3765, 3774, 3798, 3700, 3756, 3881, 3830, 3883, 3787, 3813,
        3801, 3877, 3770, 3798, 3779, 3828, 3835, 3776, 3739, 3849, 3861, 3788,
        3723, 3837, 3764, 3740, 3818, 3862, 3832, 3807, 3897, 3865, 3806, 3863,
        3857, 3790, 3863, 3714, 3784, 3781, 3876, 3803, 3708, 3785, 3762, 3755,
        3853, 3757, 3714, 3820, 3733, 3819, 3727, 3843, 3792, 3765, 3762, 3756,
        3723, 3841, 3863, 3704, 3845, 3722, 3855, 3831, 3786, 3748, 3766, 3707,
        3771, 3768, 3783, 3883, 3826, 3895, 3792, 3821, 3723, 3734, 3826, 3795,
        3856, 3743, 3803, 3725, 3774, 3713, 3749, 3711, 3800, 3710, 3743, 3732,
        3703, 3762, 3701, 3702, 3795, 3829, 3738, 3870, 3787, 3702, 3827, 3798,
        3790, 3774, 3820, 3749, 3720, 3860, 3750, 3784, 3882, 3771, 3709, 3850,
        3725, 3799, 3833, 3727, 3819, 3750, 3764, 3821, 3871, 3878, 3893, 3859,
        3761, 3728, 3834, 3741, 3751, 3881, 3814, 3872, 3739, 3741, 3756, 3822,
        3852, 3721, 3741, 3765, 3722, 3793, 3816, 3763, 3850, 3809, 3712, 3896,
        3882, 3898, 3722, 3745, 3725, 3711, 3711, 3802, 3831, 3791, 3842, 3823,
        3822, 3894, 3862, 3838, 3718, 3807, 3801, 3773, 3770, 3793, 3743, 3786,
        3728, 3720, 3881, 3815, 3894, 3792, 3819, 3703, 3894, 3855, 3834, 3794,
        3885, 3746, 3856, 3740, 3722, 3831, 3751, 3732, 3729, 3797, 3848, 3889,
        3707, 3702, 3823, 3889, 3785, 3844, 3858, 3839, 3703, 3743, 3829, 3791,
        3863, 3706, 3860, 3814, 3863, 3767, 3777, 3719, 3710, 3890, 3726, 3707,
        3889, 3861, 3838, 3824, 3859, 3806, 3802, 3714, 3791, 3740, 3804, 3712,
        3849, 3802, 3878, 3856, 3779, 3899, 3746, 3831, 3798, 3891, 3739, 3850,
        3739, 3817, 3743, 3785, 3802, 3810, 3889, 3839, 3788, 3749, 3879, 3879,
        3782, 3899, 3741, 3781, 3819, 3715, 3838, 3820, 3731, 3835, 3777, 3749,
        3894, 3765, 3777, 3866, 3759, 3731, 3729, 3750, 3773, 3875, 3715, 3876,
        3873, 3855, 3825, 3726, 3835, 3885, 3812, 3844, 3878, 3721, 3894, 3859,
        3871, 3796, 3801, 3864, 3769, 3826, 3886, 3883, 3730, 3821, 3829, 3768,
        3773, 3831, 3738, 3739, 3747, 3864, 3818, 3792, 3755, 3715, 3870, 3849,
        3817, 3807, 3721, 3818, 3817, 3794, 3812, 3841, 3709, 3700, 3741, 3822,
        3848, 3870, 3705, 3787, 3704, 3879, 3728, 3756, 3780, 3747, 3808, 3734,
        3836, 3755, 3898, 3813, 3717, 3775, 3897, 3796, 3804, 3872, 3761, 3769,
        3791, 3817, 3751, 3753, 3712, 3785, 3785, 3824, 3880, 3869, 3753, 3846,
        3720, 3872, 3808, 3876, 3819, 3734, 3791, 3741, 3891, 3756, 3897, 3855,
        3758, 3794, 3856, 3719, 3842, 3821, 3773, 3811, 3855, 3840, 3781, 3807,
        3853, 3888, 3872, 3856, 3867, 3859, 3881, 3743, 3727, 3816, 3844, 3816,
        3737, 3826, 3767, 3894, 3867, 3810, 3842, 3853, 3713, 3829, 3752, 3705,
        3724, 3725, 3843, 3813, 3809, 3726, 3829, 3861, 3889, 3823, 3791, 3848,
        3768, 3890, 3703, 3796, 3829, 3724, 3849, 3737, 3782, 3796, 3816, 3759,
        3890, 3790, 3812, 3736, 3850, 3899, 3734, 3764, 3869, 3852, 3896, 3853,
        3851, 3848, 3855, 3840, 3819, 3729, 3859, 3892, 3876, 3822, 3724, 3766,
        3715, 3785, 3845, 3838, 3795, 3863, 3798, 3896, 3762, 3812, 3803, 3761,
        3752, 3844, 3801, 3895, 3729, 3708, 3719, 3848, 3818, 3711, 3866, 3822,
        3800, 3703, 3855 };
static const unsigned short TEMPERATURE[300] = { 2016, 1999, 1919, 1945, 1966,
        1959, 2056, 2073, 1984, 1946, 1949, 1957, 1900, 1994, 2059, 2028, 2056,
        1902, 1926, 1932, 2063, 2019, 1970, 1901, 2080, 1997, 2087, 1918, 1903,
        2096, 2071, 2084, 2023, 1947, 1985, 1977, 1980, 1933, 1976, 2004, 2033,
        2033, 1905, 1991, 2011, 2060, 2082, 1998, 1910, 2005, 1985, 1913, 1942,
        2000, 2058, 2031, 2025, 2088, 2033, 2028, 2030, 1988, 1902, 1915, 1932,
        1940, 1909, 1908, 2029, 2057, 2038, 2060, 2047, 2073, 2078, 1997, 2084,
        1959, 1913, 1953, 2063, 1996, 2003, 2040, 2080, 1973, 1958, 1986, 1940,
        2061, 1995, 2073, 1979, 1963, 1972, 2023, 1948, 2034, 2006, 1990, 2015,
        1953, 2097, 1926, 1909, 2054, 2069, 2095, 1977, 2087, 1900, 2068, 1975,
        1997, 2019, 2001, 1911, 1974, 2083, 2007, 2027, 2048, 2011, 2004, 1940,
        1925, 2000, 1910, 2073, 1949, 2013, 2065, 1904, 1991, 1919, 2097, 2082,
        1978, 2039, 1999, 1980, 1939, 1904, 2073, 2096, 2050, 2003, 1915, 2056,
        2054, 2016, 1957, 1922, 2081, 2015, 1988, 1924, 1991, 1941, 1910, 2072,
        1997, 1984, 2072, 1974, 1902, 2019, 1994, 1950, 2013, 2007, 1952, 1904,
        1995, 1958, 2074, 2086, 2047, 2072, 2007, 1980, 2093, 1998, 2002, 2022,
        2082, 1952, 2070, 1962, 1931, 1961, 2099, 2077, 2039, 1949, 2080, 1921,
        1976, 1913, 2038, 1984, 2099, 1925, 1971, 2006, 1931, 2083, 2033, 2048,
        2066, 1923, 2021, 2082, 2078, 1994, 1910, 1932, 2042, 2091, 2059, 2083,
        2023, 2033, 1988, 2032, 1908, 2083, 2039, 2062, 1914, 2056, 1990, 2065,
        1933, 1909, 1999, 1986, 2091, 1935, 1917, 1951, 2094, 1985, 2090, 2025,
        2040, 1928, 2076, 1900, 2063, 1988, 2096, 1996, 2021, 2089, 1909, 2073,
        1940, 1995, 2075, 1914, 2057, 2068, 1916, 1957, 2027, 1968, 2053, 2002,
        2098, 1936, 1953, 2042, 2086, 2098, 1963, 2029, 1915, 2064, 2024, 2071,
        2009, 1986, 1920, 1949, 1912, 1922, 1974, 2080, 1990, 2056, 1997, 1950,
        2066, 2066, 2005, 1931, 2003, 1972, 2049 };
static const unsigned short LIGHT[100] = { 4359, 4449, 4468, 4314, 4333, 4335,
        4470, 4331, 4425, 4300, 4370, 4439, 4381, 4336, 4309, 4332, 4446, 4327,
        4401, 4374, 4325, 4331, 4417, 4318, 4356, 4365, 4394, 4458, 4400, 4459,
        4399, 4378, 4419, 4358, 4479, 4335, 4375, 4418, 4435, 4409, 4414, 4347,
        4315, 4334, 4414, 4453, 4385, 4336, 4459, 4352, 4478, 4358, 4373, 4372,
        4376, 4321, 4331, 4478, 4354, 4357, 4386, 4459, 4411, 4356, 4368, 4313,
        4491, 4407, 4409, 4452, 4381, 4433, 4471, 4312, 4354, 4337, 4311, 4425,
        4309, 4472, 4369, 4376, 4353, 4460, 4487, 4415, 4450, 4432, 4411, 4419,
        4421, 4431, 4482, 4318, 4406, 4492, 4495, 4359, 4446, 4378 };

Define_Module(Client);

void Client::initialize() {
    // set global address
    // simulate the pseudo-assigned MAC and IPv6 address creation
//    this->msgQueue = new std::queue();
    this->soilCount = 0;
    this->lightCount = 0;
    this->temperatureCount = 0;
    this->moistureCount = 0;

    // create MAC
    this->macAddress = new MacAddress(getId());

    // create self IPv6 sddress
    this->ipAddress = new IpAddress(this->macAddress);

    // set gloabl server address
    // network address aaaa::/64
    // suppose it is a MAC-48 from 64 bit by putting ff::fe to midle
    // server address aaaa::ff::fe:1
    this->serverAddress = new IpAddress(170, 170, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            255, 254, 0, 0, 1);

    if (DEBUG) {
        std::cout << this->getFullPath() << " has mac address ";
        this->macAddress->print();
        std::cout << this->getFullPath()
                << " has tentative link-local address ";
        this->ipAddress->print();
        std::cout << endl;
    }

    this->packetNumber = 0;

    /* Contiki test scheme */
    switch ((int) getModuleByPath("^.^")->par("scheme").doubleValue()) {
    case 1: /* one manual event */
    {
        if (this->getParentModule()->getId()
                == simulation.getModuleByPath("client[8]")->getId())
            selfTimer(
                    getModuleByPath("^.^")->par("setupDelay").doubleValue()
                            + 10, APP_SENSING_FLAG);

        if (this->getParentModule()->getId()
                == simulation.getModuleByPath("client[8]")->getId())
            selfTimer(
                    getModuleByPath("^.^")->par("setupDelay").doubleValue()
                            + 20, APP_SENSING_FLAG);

        if (this->getParentModule()->getId()
                == simulation.getModuleByPath("client[8]")->getId())
            selfTimer(
                    getModuleByPath("^.^")->par("setupDelay").doubleValue()
                            + 30, APP_SENSING_FLAG);

        break;
    } /* one event */

    case 2: /* ignite periodically */
    {
        selfTimer(getModuleByPath("^.^")->par("setupDelay").doubleValue(),
                RPL_SET_UP_DELAY);

        break;
    } /* ignite periodically */

    case 3: /* RPL test */
    {
        // TODO
        break;
    }/* RPL test */

    case 4: {
        // Send data periodically according to requirement. (High frequency)
        initSensors(true);
        break;
    }
    case 5: {
        initSensors(false);
        break;
    }
    default:
        if (DEBUG)
            ev << "Just construct " << endl;
        break;
    }

    if (getParentModule() != NULL) {
        std::ofstream myfile;
        char myfilename[100];

        sprintf(myfilename, "client_data/id_%s_data_light.txt",
                getParentModule()->getFullName());
        myfile.open(myfilename);
        myfile.close();

        sprintf(myfilename, "client_data/id_%s_data_temperature.txt",
                getParentModule()->getFullName());
        myfile.open(myfilename);
        myfile.close();

        sprintf(myfilename, "client_data/id_%s_data_moisture.txt",
                getParentModule()->getFullName());
        myfile.open(myfilename);
        myfile.close();

        sprintf(myfilename, "client_data/id_%s_data_soil.txt",
                getParentModule()->getFullName());
        myfile.open(myfilename);
        myfile.close();
    }
}

void Client::initSensors(bool isHighFreq) {
    if (DEBUG)
        std::cout << this->getFullPath() << " init sensors" << endl;
    double setupDelay = getModuleByPath("^.^")->par("setupDelay").doubleValue();
    selfTimer(
            setupDelay
                    + getModuleByPath("^.^")->par("lightSensingDelay").doubleValue(),
            APP_SEND_LIGHT_DATA);
    selfTimer(
            setupDelay
                    + getModuleByPath("^.^")->par("moistureSensingDelay").doubleValue(),
            APP_SEND_MOISTURE_DATA);
    if (isHighFreq) {
        selfTimer(
                setupDelay
                        + getModuleByPath("^.^")->par(
                                "temperatureSensingDelayHigh").doubleValue(),
                APP_SEND_TEMPERATURE_DATA_HIGH);
        selfTimer(
                setupDelay
                        + getModuleByPath("^.^")->par("soilSensingDelayHigh").doubleValue(),
                APP_SEND_SOIL_DATA_HIGH);
    } else {
        selfTimer(
                setupDelay
                        + getModuleByPath("^.^")->par(
                                "temperatureSensingDelayLow").doubleValue(),
                APP_SEND_TEMPERATURE_DATA_LOW);
        selfTimer(
                setupDelay
                        + getModuleByPath("^.^")->par("soilSensingDelayLow").doubleValue(),
                APP_SEND_SOIL_DATA_LOW);
    }
}

void Client::processSelfMessage(cPacket* packet) {
    switch (packet->getKind()) {
    case COMMAND: /* Command */
    {
        switch (check_and_cast<Command*>(packet)->getNote()) {
        case RPL_SET_UP_DELAY: /* set up delay */
        {
            newData();
            break;
        }/* set up delay*/

        case APP_SENSING_FLAG: /* new data */
        {
            // Timer for next message
            if ((int) getModuleByPath("^.^")->par("scheme").doubleValue()
                    == 2) {
#ifdef MAX
                if (++this->packetNumber < MAX) // control maximum number
#else
                ++this->packetNumber;
#endif
                newData();
            }

            break; /* new data */
        }

        case APP_READY_TO_SEND: /* ready to send */
        {
            // begin send data
            sendData();
            break;
        } /* ready to send */
        case APP_SEND_LIGHT_DATA: {
            sendData("1 Light data", APP_SEND_LIGHT);
            selfTimer(
                    getModuleByPath("^.^")->par("lightSensingDelay").doubleValue(),
                    APP_SEND_LIGHT_DATA);
            break;
        }
        case APP_SEND_TEMPERATURE_DATA_HIGH: {
            sendData("2 Temperature data", APP_SEND_TEMPERATURE);
            selfTimer(
                    getModuleByPath("^.^")->par("temperatureSensingDelayHigh").doubleValue(),
                    APP_SEND_TEMPERATURE_DATA_HIGH);
            break;
        }
        case APP_SEND_TEMPERATURE_DATA_LOW: {
            sendData("2 Temperature data", APP_SEND_TEMPERATURE);
            selfTimer(
                    getModuleByPath("^.^")->par("temperatureSensingDelayLow").doubleValue(),
                    APP_SEND_TEMPERATURE_DATA_LOW);
            break;
        }
        case APP_SEND_MOISTURE_DATA: {
            sendData("3 Moisture data", APP_SEND_MOISTURE);
            selfTimer(
                    getModuleByPath("^.^")->par("moistureSensingDelay").doubleValue(),
                    APP_SEND_MOISTURE_DATA);
            break;
        }
        case APP_SEND_SOIL_DATA_HIGH: {
            sendData("4 SOIL data", APP_SEND_SOIL);
            selfTimer(
                    getModuleByPath("^.^")->par("soilSensingDelayHigh").doubleValue(),
                    APP_SEND_SOIL_DATA_HIGH);
            break;
        }
        case APP_SEND_SOIL_DATA_LOW: {
            sendData("4 SOIL data", APP_SEND_SOIL);
            selfTimer(
                    getModuleByPath("^.^")->par("soilSensingDelayHigh").doubleValue(),
                    APP_SEND_SOIL_DATA_LOW);
            break;
        }
        case APP_SEND_DATA_REAL: {
            sendDataReal();
        }
        default:
            ev << "Unknown command" << endl;
            break;
        }
        delete packet; // done command
        break;
        /* Command */
    }

    default:
        delete packet;
        ev << "Unknown kind" << endl;
        break;
    }
}

void Client::processUpperLayerMessage(cPacket*) {
    /* Highest layer */
    return;
}

void Client::processLowerLayerMessage(cPacket*) {
}

/*
 * Start timer to begin to collect data
 */
void Client::newData() {
    int sendInterval = 55; // seconds
    int restPeriod = 10; // seconds

    // avoid immediately sending + simulate not-synchronized clock
    double time = 0;

//  if (simTime() + sendInterval + restPeriod < getModuleByPath("^.^")->par("timeLimit").doubleValue())
    selfTimer(sendInterval + restPeriod, APP_SENSING_FLAG);

    if (getModuleByPath("^.^")->par("rand").doubleValue() == 0)
        time = (rand() % 10000) / 10000.0 * sendInterval;
    else if (getModuleByPath("^.^")->par("rand").doubleValue() == 1)
        time = intuniform(0, 10000) / 10000.0 * sendInterval;

    if (DEBUG)
        this->getParentModule()->bubble("Data");

//  if (simTime().dbl() + sendInterval < getModuleByPath("^.^")->par("timeLimit").doubleValue())
    selfTimer(time, APP_READY_TO_SEND);
}

/*
 * Collect data from outside world and send toward server
 */
void Client::sendData() {
    // create data to send
    char buf[30];
    int len = sprintf(buf, "Hello %d from %s", packetNumber,
            getParentModule()->getFullName());

    // hack port, address
    int destinationPort = UDP_SERVER_PORT;
    int destinationAddress =
    simulation.getModuleByPath("server.net")->getId();

    sendMessage(buf, len, destinationPort, destinationAddress);

    /* End to end statistics */
    (check_and_cast<Statistic*>(simulation.getModuleByPath("statistic"))->registerStatistic(
    APP_SEND));
}

void Client::sendData(char* message, int type) {

    char buf[100] = { 0 };
    char data[100] = { 0 };
    char myfilename[100] = { 0 };
    int len = 0;

    // hack port, address
    int destinationPort = UDP_SERVER_PORT;
    int destinationAddress = simulation.getModuleByPath("server.net")->getId();

    if (type != APP_SEND) {
        std::ofstream myfile;
        switch (type) {
        case APP_SEND_LIGHT:
            buf[0] = '\0';
            data[0] = '\0';
            myfilename[0] = '\0';

            sprintf(data, "1/%d", LIGHT[lightCount++ % 100]);
            sprintf(myfilename, "client_data/id_%s_data_light.txt",
                    getParentModule()->getFullName());

            myfile.open(myfilename, std::ios::app);
            break;
        case APP_SEND_TEMPERATURE:
            buf[0] = '\0';
            data[0] = '\0';
            myfilename[0] = '\0';

            sprintf(data, "2/%d", TEMPERATURE[temperatureCount++ % 300]);
            sprintf(myfilename, "client_data/id_%s_data_temperature.txt",
                    getParentModule()->getFullName());

            myfile.open(myfilename, std::ios::app);
            break;
        case APP_SEND_MOISTURE:
            buf[0] = '\0';
            data[0] = '\0';
            myfilename[0] = '\0';

            sprintf(data, "3/%d", MOISUTRE[moistureCount++ % 500]);
            sprintf(myfilename, "client_data/id_%s_data_moisture.txt",
                    getParentModule()->getFullName());

            myfile.open(myfilename, std::ios::app);
            break;
        case APP_SEND_SOIL:
            buf[0] = '\0';
            data[0] = '\0';
            myfilename[0] = '\0';

            sprintf(data, "4/%d,%d", SOIL_PH[soilCount % 1500],
                    SOIL_MOISTURE[soilCount++ % 1500]);
            sprintf(myfilename, "client_data/id_%s_data_soil.txt",
                    getParentModule()->getFullName());

            myfile.open(myfilename, std::ios::app);
            break;
        }

        len = sprintf(buf, "%s|%s", getParentModule()->getFullName(), data);

        string data2 = data;
        myfile << simTime().inUnit(SIMTIME_MS);
        myfile << ",";
        myfile << data2.substr(2, data2.size());
        myfile << "\n";
        myfile.close();
    } else {
        buf[0] = '\0';
        len = sprintf(buf, message);
    }
//    len = sprintf(buf, message);
    if (getModuleByPath("^.^")->par("usingMsgQueue")) {
        this->dataQueue.push_back(data);
        selfTimer(0.5f, APP_SEND_DATA_REAL);
    } else {
        sendMessage(buf, len, destinationPort, destinationAddress);

        if (DEBUG) {
            std::cout << "Sending data " << buf << endl;
            this->bubble(message);
        }
    }

    /* End to end statistics */
    (check_and_cast<Statistic*>(simulation.getModuleByPath("statistic"))->registerStatistic(
            type));
    (check_and_cast<Statistic*>(simulation.getModuleByPath("statistic"))->registerStatistic(
    APP_SEND));
}

void Client::sendDataReal() {
    if (this->dataQueue.size() == 0) {
        return;
    }

    std::string message = getParentModule()->getFullName();
    message += "|";
    for (unsigned int i = 0; i < this->dataQueue.size(); i++) {
        string data = this->dataQueue.at(i);
        message += data + "|";
    }
    message = message.substr(0, message.size() - 1);

    char buf[128] = { 0 };
    int len = sprintf(buf, message.c_str());
    int destinationPort = UDP_SERVER_PORT;
    int destinationAddress = simulation.getModuleByPath("server.net")->getId();
    sendMessage(buf, len, destinationPort, destinationAddress);

    if (DEBUG) {
        std::cout << "Sending data " << buf << endl;
    }

    this->dataQueue.clear();
}

void Client::sendData(char* message) {
    sendData(message, APP_SEND);
}

/*
 * Send messge API
 */
void Client::sendMessage(char *value, int len, int destinationPort,
        int destinationAddress) {
    // intialisation
    Data *data = new Data;
    data->setKind(DATA);
    data->setByteLength(len);

    // meta-data
    data->setTime(simTime().dbl());

    // control-data
    data->setDestinationPort(destinationPort);
    data->setDestinationIPAddress(destinationAddress);

    // data
    if (getModuleByPath("^.^")->par("usingLZW")) {
        std::vector<char> compressed;
        LZWHelper::compress(value, std::back_insert(compressed));

        std::stringstream result;
        copy(compressed.begin(), compressed.end(), std::ostream_iterator<char>(result, ""));
        data->setValue(result);
    } else {
        data->setValue(value);
    }

    sendMessageToLower(data);
}

}
;
// namespaces
