{
  "targets": [
    {
      "target_name": "addon",
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      'conditions': [
        ['OS=="linux"', {
          'libraries': ['-lX11', '-lXtst'],
        }],
        ['OS=="win"', {
          "sources": [ 
            "src/input_device_ctrl_win.cc"
          ],
        }]
        ],

      "sources": [ 
          "src/addon.cc"
      ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
    }
  ]
}