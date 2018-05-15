/*
 * Copyright (c) 2012-2015 VMware, Inc.  All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License.  You may obtain a copy
 * of the License at http://www.apache.org/licenses/LICENSE-2.0
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, without
 * warranties or conditions of any kind, EITHER EXPRESS OR IMPLIED.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 */

package com.vmware.identity.interop.directory;

import org.apache.commons.lang.SystemUtils;

public class DirectoryException extends RuntimeException 
{
	private static final long serialVersionUID = 8095413793162663579L;

	private int _errCode = -1;

    public DirectoryException (int errCode, String errMsg)
    {
        super(errMsg);
        
    	_errCode = errCode;
    }

    @Override
    public String toString()
    {
        return 	super.toString() +
        		SystemUtils.LINE_SEPARATOR +
        		String.format(
	        				"VMware Directory error [code: %d]", 
	        				this._errCode);
    }

    public int getErrorCode()
    {
        return _errCode;
    }
}
