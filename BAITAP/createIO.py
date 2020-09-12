import time
import os
from watchdog.observers import Observer
from watchdog.events import PatternMatchingEventHandler

def on_created(event):
	print(f"hey, {event.src_path} has been created!")
	pathF = event.src_path
	fileName = pathF[2:len(pathF)-4]
	try:
		f1 = open(fileName+'.inp',"w")
		f2 = open(fileName+'.out',"w")		
		f1.close()
		f2.close()
	except:
		return

	print("File's name is:" +  fileName)
if __name__ == "__main__":
	patterns = "*"
	ignore_patterns = ""
	ignore_directories = False
	case_sensitive = True
	my_event_handler = PatternMatchingEventHandler(patterns, ignore_patterns, ignore_directories, case_sensitive)
	#
	my_event_handler.on_created = on_created
	#
	path = "."
	go_recursively = True
	my_observer = Observer()
	my_observer.schedule(my_event_handler, path, recursive=go_recursively)
	#
	my_observer.start()
	try:
		while True:
			time.sleep(1)
	except KeyboardInterrupt:
		my_observer.stop()
		my_observer.join()