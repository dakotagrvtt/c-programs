# Output web content to file

curl {url} > {file.name}

## Double the content, double the >

curl {url} >> {file.name}

RESULT:
cat {file.name}

{url content}
{url content}
