import os
import os.path
import sys
import re
import sys

class Directory:
    def __init__(self, directory):
        if not os.path.exists(directory):
            raise OSError
        self.dir = directory
        
        self.files = ()

    def scan(self, dir):
        html = re.compile(r'(\.htm)|(\.html)$')
        self.files = [file for file in os.listdir(dir) if re.search(html, file)] # add .html later
        return self.files
                
class Browser:
    def __init__(self, directory):
        self.html = ''
        self.dir = directory
        self.head = r'<html><body>'
        self.filelist = directory.scan(directory.dir)
        self.end = r'</body></html>'

    def linkify(self):
        body = []
        for file in self.filelist:
            body.append(file.join(['<a href="', '">']) + os.path.splitext(file)[0] + r'</a> <br>')
            self.body = '\n'.join(body)
        
        
    def export(self, filename):
        self.linkify()
        text = self.head + self.body + self.end
        with open(filename, 'w') as browserfile:
                browserfile.write(text) 


if __name__ == '__main__':
    directory = Directory(sys.argv[1])
    directory.scan(directory.dir)

    browser = Browser(directory)
    browser.linkify()
    browser.export(sys.argv[2])
