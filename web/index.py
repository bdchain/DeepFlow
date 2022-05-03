import os
import sys
import json
import web
from db_request import *


urls = (
    # '/(.*)', 'hello'
    "/block", "block"
)
app = web.application(urls, globals())

# class hello:
#     def GET(self, name):
#         if not name:
#             name = 'World'
#         return 'Hello, ' + name + '!'

class block:
    def _block_get_parser(self, param):
        ret = ""
        try:
            if param.height:
                request_height = int(param.height)
                block = get_block_by_height(request_height)
                if block:
                    ret = block.ToJson()
                else:
                    ret = "Block Not Found."
            elif param.id:
                if len(param.id) != 64:
                    ret = "Invalid Block ID Provided."
                else:
                    block = get_block_by_id(param.id)
                    if block:
                        ret = block.ToJson()
                    else:
                        ret = "Block Not Found."
            elif param.start_height and param.end_height:
                start_height = int(param.start_height)
                end_height   = int(param.end_height)
                blocks = get_block_by_height_range(start_height, end_height)
                if len(blocks) == 0:
                    ret = "No Block Found in the Given Height Range."
                else:
                    block_dict = {"blocks": []}
                    for b in blocks:
                        block_dict["blocks"].append(b.ToDict())
                    ret = json.dumps(block_dict)
            else:
                ret = "Invalid Request Parameter Provided."
        except ValueError:
            ret = "Invalid Request Parameter Provided."
        return ret + '\n'

    def GET(self):
        param = web.input(height=None, id=None, start_height=None, end_height=None)
        res = self._block_get_parser(param)
        return res

if __name__ == "__main__":
    app.run()

