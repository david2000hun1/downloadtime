#include <iostream>

int GetInput (std::string text){
	
	int x {};
	std::cout << text;
	std::cin >> x;
	return x;
	}


int main(){

	int FileUnit {GetInput("Choose the unit of the file you are downloading: 1=KB, 2=MB, 3=GB, 4=TB ")};
	double FileSize = GetInput("The size of the file in the given unit: ");
	int DownloadSpeedUnit {GetInput("Choose the unit of your download speed: 1=Kbps 2=Mbps 3=Gbps 4=KBps 5=MBps 6=GBps ")};
	double DownloadSpeed = GetInput("Download speed in the given unit: ");
	
	if (DownloadSpeedUnit < 4){
		DownloadSpeedUnit = DownloadSpeedUnit + 3;
		DownloadSpeed = DownloadSpeed / 8;
		}

	if(DownloadSpeedUnit - 3 < FileUnit){
		for(int i=0; i<FileUnit - (DownloadSpeedUnit - 3); i++){
			FileUnit--;
			FileSize = FileSize * 1024;
			}
		} else if (DownloadSpeedUnit - 3 > FileUnit){
			for (int i=0; i<DownloadSpeedUnit - 3 - FileUnit; i++){
				FileUnit++;
				FileSize = FileSize / 1024;
				}
			}
	
	int SecondsLeft {};
	int MinutesLeft {};
	int HoursLeft {};

	SecondsLeft = FileSize / DownloadSpeed;
	if (SecondsLeft > 50){ 
		MinutesLeft = SecondsLeft / 60;
		SecondsLeft = SecondsLeft % 60;
		}
	if (MinutesLeft > 59){
		HoursLeft = MinutesLeft / 60;
		MinutesLeft = MinutesLeft % 60;
		}
	
	std::cout << HoursLeft << " hours, " << MinutesLeft << " minutes, and " << SecondsLeft << " seconds are left. " << '\n';
	return 0;

	}
