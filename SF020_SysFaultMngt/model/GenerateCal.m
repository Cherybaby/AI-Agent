% 在Workspace中创建FaultCal，将EXCEL中的数据复制过来
% 获取数据行数
numRows = size(FaultCal, 1);

if numRows > 256
     error('行数 %d 超出范围 (256)', numRows);
end

% 初始化结果数组
resultArray = zeros(numRows, 1, 'uint32');

% 初始化字符串
str = '[';

% 处理每一行数据
for i = 1:numRows
    % 提取当前行的各列数据
    col1 = uint8(FaultCal(i, 1));  % 第一列 -> uint8
    col2 = uint8(FaultCal(i, 2));  % 第二列 -> uint8
    col3 = uint8(FaultCal(i, 3));  % 第三列 -> uint8
    col4 = logical(FaultCal(i, 4)); % 第四列 -> bool
    col5 = logical(FaultCal(i, 5)); % 第五列 -> bool
    
    % 验证第三列值范围 (0-3)
    if col3 > 3
        error('第 %d 行第三列值 %d 超出范围 (0-3)', i, col3);
    end
    
    % 位拼接操作
    value = uint32(0);


    
    % 第一列: bit0-bit7
    value = bitor(value, uint32(col1));
    
    % 第二列: bit8-bit15
    value = bitor(value, bitshift(uint32(col2), 8));
    
    % 第三列: bit16-bit17
    value = bitor(value, bitshift(uint32(col3), 16));
    
    % 第四列: bit18
    if col4
        value = bitor(value, bitshift(uint32(1), 18));
    end
    
    % 第五列: bit19
    if col5
        value = bitor(value, bitshift(uint32(1), 19));
    end
    
    % 存储结果
    resultArray(i) = value;

    % 添加当前元素
    str = [str, num2str(value), '; '];
end

% 添加结束括号
str = [str, ']'];

